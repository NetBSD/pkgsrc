$NetBSD: patch-src_curses.h,v 1.1.1.1 2000/07/14 10:37:18 rh Exp $

--- src/curses.h.orig	Mon Jun 26 22:51:42 2000
+++ src/curses.h	Tue Jul 11 09:54:38 2000
@@ -4,7 +4,7 @@
 #include <signal.h>		/* updates only needed in interactive modes */
 #define XOFFSET 0		/* blank columns to leave at the left */
 #define YOFFSET 0		/* blank lines to leave at the top */
-#if HAVE_NCURSES_H
+#if 1
 #include <ncurses.h>
 #else
 #include <curses.h>
