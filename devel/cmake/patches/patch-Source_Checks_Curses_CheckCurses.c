$NetBSD: patch-Source_Checks_Curses_CheckCurses.c,v 1.2 2018/09/08 06:55:51 adam Exp $

Use curses.h provided by buildlink.

--- Source/Checks/Curses/CheckCurses.c.orig	2018-08-09 12:14:07.000000000 +0000
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
 
 int main()
 {
-  curses_version();
+  flash();
   return 0;
 }
