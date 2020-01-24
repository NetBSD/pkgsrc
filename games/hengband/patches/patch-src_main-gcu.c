$NetBSD: patch-src_main-gcu.c,v 1.1 2020/01/24 13:33:33 pho Exp $

A WINDOW object in ncurses is an opaque pointer and thus we cannot
access its members directly.

--- src/main-gcu.c.orig	2017-04-27 09:55:49.000000000 +0000
+++ src/main-gcu.c
@@ -600,7 +600,7 @@ static errr Term_xtra_gcu_alive(int v)
       mvcur(curscr->cury, curscr->curx, LINES - 1, 0);
 #else
       /* this moves curses to bottom right corner */
-      mvcur(curscr->_cury, curscr->_curx, LINES - 1, 0);
+      mvcur(getcury(curscr), getcurx(curscr), LINES - 1, 0);
 #endif
 
       /* Exit curses */
@@ -736,7 +736,7 @@ static void Term_nuke_gcu(term *t)
    mvcur(curscr->cury, curscr->curx, LINES - 1, 0);
 #else
    /* This moves curses to bottom right corner */
-   mvcur(curscr->_cury, curscr->_curx, LINES - 1, 0);
+   mvcur(getcury(curscr), getcurx(curscr), LINES - 1, 0);
 #endif
 
    /* Flush the curses buffer */
