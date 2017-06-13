/* Last line fish v0.3 - simple ncurses fullscreen viewer
   2014 (c) Kurashov A.K. Under GNU GPLv3 */

#include <curses.h>

int main()
{
	char c;

	// ncurses init
	initscr();
	cbreak();		// disable chars' buffer
	noecho();		// disable echo
	curs_set(0);		// disable cursor
	clear();
	// reading text from stdin and put to stdout
	while ((c = getch()) != EOF)
		if (c != '\n')
			addch(c);
	// reinit tty
	freopen("/dev/tty", "rw", stdin);
	// show data
	refresh();
	// waiting until keypress
	getch();
	// clear and close ncurses
	clear();
	refresh();
	endwin();
	// ANSI clear (for left upper corner)
	putchar(0x1b);
	putchar('c');
	// exit
	return 0;
}
