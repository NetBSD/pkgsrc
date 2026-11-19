$NetBSD: patch-src_ui_core.c,v 1.4 2026/11/19 15:32:32 ktnb Exp $

sys/termios.h is needed for TIOCGWINZ on Solaris/Illumos

--- src/ui/core.c.orig	2026-11-19 09:24:26.000000000 +0000
+++ src/ui/core.c
@@ -25,6 +25,10 @@
 #include <curses.h>
 #endif
 
+#ifdef HAVE_SYS_TERMIOS_H
+#include <sys/termios.h>
+#endif
+
 #include "log.h"
 #include "common.h"
 #include "command/cmd_defs.h"
@@ -51,6 +55,7 @@ static WINDOW* main_scr;
 static gboolean perform_resize = FALSE;
 static GTimer* ui_idle_time;
 static WINDOW* main_scr;
+static SCREEN* main_screen;
 
 static void _ui_draw_term_title(void);
 
@@ -67,7 +72,7 @@ _ui_close(void)
     endwin();
     delwin(main_scr);
     main_scr = NULL;
-    delscreen(set_term(NULL));
+    delscreen(main_screen);
 }
 
 void
@@ -75,7 +80,8 @@ ui_init(void)
 {
     log_info("Initialising UI");
     prof_add_shutdown_routine(_ui_close);
-    main_scr = initscr();
+    main_screen = newterm(NULL, stdout, stdin);
+    main_scr = stdscr;
     nonl();
     cbreak();
     noecho();
