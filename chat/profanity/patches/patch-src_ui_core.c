$NetBSD: patch-src_ui_core.c,v 1.3 2026/11/17 22:09:41 ktnb Exp $

sys/termios.h is needed for TIOCGWINZ on Solaris/Illumos

--- src/ui/core.c.orig	2026-10-15 13:56:02.000000000 +0000
+++ src/ui/core.c
@@ -29,6 +29,10 @@
 #include <curses.h>
 #endif
 
+#ifdef HAVE_SYS_TERMIOS_H
+#include <sys/termios.h>
+#endif
+
 #include "log.h"
 #include "common.h"
 #include "command/cmd_defs.h"
@@ -56,6 +60,7 @@ static WINDOW* main_scr;
 static gboolean perform_resize = FALSE;
 static GTimer* ui_idle_time;
 static WINDOW* main_scr;
+static SCREEN* main_screen;
 
 #ifdef HAVE_LIBXSS
 static Display* display;
@@ -76,7 +81,7 @@ _ui_close(void)
     endwin();
     delwin(main_scr);
     main_scr = NULL;
-    delscreen(set_term(NULL));
+    delscreen(main_screen);
 }
 
 void
@@ -84,7 +89,8 @@ ui_init(void)
 {
     log_info("Initialising UI");
     prof_add_shutdown_routine(_ui_close);
-    main_scr = initscr();
+    main_screen = newterm(NULL, stdout, stdin);
+    main_scr = stdscr;
     nonl();
     cbreak();
     noecho();
