$NetBSD: patch-Source_Checks_Curses_CheckCurses.c,v 1.3 2024/04/02 17:27:41 adam Exp $

Use curses.h provided by buildlink.

--- Source/Checks/Curses/CheckCurses.c.orig	2024-03-21 13:32:22.000000000 +0000
+++ Source/Checks/Curses/CheckCurses.c
@@ -1,15 +1,7 @@
-#if defined(CURSES_HAVE_NCURSES_H)
-#  include <ncurses.h>
-#elif defined(CURSES_HAVE_NCURSES_NCURSES_H)
-#  include <ncurses/ncurses.h>
-#elif defined(CURSES_HAVE_NCURSES_CURSES_H)
-#  include <ncurses/curses.h>
-#else
-#  include <curses.h>
-#endif
+#include <curses.h>
 
 int main(void)
 {
-  curses_version();
+  flash();
   return 0;
 }
