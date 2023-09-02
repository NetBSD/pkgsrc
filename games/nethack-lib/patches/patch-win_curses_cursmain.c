$NetBSD: patch-win_curses_cursmain.c,v 1.1 2023/09/02 13:45:14 rhialto Exp $

Include the window resizing code also for NetBSD curses.

--- win/curses/cursmain.c.orig	2023-02-15 21:52:57.000000000 +0000
+++ win/curses/cursmain.c
@@ -277,7 +277,7 @@ curses_get_nh_event()
         do_reset = TRUE;
     }
 #endif
-#ifdef NCURSES_VERSION          /* Is there a better way to detect ncurses? */
+#if 1 /* def NCURSES_VERSION */         /* Is there a better way to detect ncurses? */
     if (is_term_resized(term_rows, term_cols)) {
         if (!isendwin()) {
             endwin();
