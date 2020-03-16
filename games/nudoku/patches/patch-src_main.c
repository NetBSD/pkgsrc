$NetBSD: patch-src_main.c,v 1.1 2020/03/16 12:59:02 fcambus Exp $

- Add missing <locale.h> header, for setlocale.
- Use wgetch(grid) instead of getch(), otherwise wmove() doesn't
  move the cursor in the grid window.

--- src/main.c.orig	2019-07-30 09:50:49.000000000 +0000
+++ src/main.c
@@ -19,7 +19,8 @@ along with this program. If not, see <ht
 */
 
 /* INCLUDES */
-#include "gettext.h"			/* gettext */
+#include <libintl.h>			/* gettext */
+#include <locale.h>				/* setlocale */
 #include <stdlib.h>				/* rand, srand */
 #include <unistd.h>				/* getopt */
 #include <ncurses.h>			/* ncurses */
@@ -294,6 +295,7 @@ static void init_windows(void)
 	status = newwin(STATUS_LINES, STATUS_COLS, STATUS_Y, STATUS_X);
 
 	grid = newwin(GRID_LINES, GRID_COLS, GRID_Y, GRID_X);
+	keypad(grid, true);
 	_draw_grid();
 
 	infobox = newwin(INFO_LINES, INFO_COLS, INFO_Y, INFO_X);
@@ -497,7 +499,7 @@ int main(int argc, char *argv[])
 #endif // DEBUG
 		refresh();
 		wrefresh(grid);
-		key = getch();
+		key = wgetch(grid);
 		// clear status window
 		werase(status);
 		switch(key)
