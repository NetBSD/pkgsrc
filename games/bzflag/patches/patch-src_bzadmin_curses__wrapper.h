$NetBSD: patch-src_bzadmin_curses__wrapper.h,v 1.1 2019/06/22 13:29:19 nia Exp $

Support NetBSD curses.

--- src/bzadmin/curses_wrapper.h.orig	2018-10-18 10:39:15.000000000 +0000
+++ src/bzadmin/curses_wrapper.h
@@ -28,7 +28,7 @@
 
 // if we have ncurses.h, just include it
 #ifdef HAVE_NCURSES_H
-#include <ncurses.h>
+#include <curses.h>
 #define COLOR_BGDEFAULT -1
 #define COLOR_FGDEFAULT -1
 #endif // ncurses
