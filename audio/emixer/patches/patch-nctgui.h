$NetBSD: patch-nctgui.h,v 1.1 2013/10/14 13:33:31 roy Exp $

--- nctgui.h.orig	1999-12-28 00:47:02.000000000 +0000
+++ nctgui.h
@@ -8,8 +8,7 @@
 */
 
 /* include files used by gui.c and main.c */
-#include <ncurses.h>
-#include <slang/slang.h>
+#include <curses.h>
 #include <string.h>
 
 /* defines used by gui.c and main.c */
