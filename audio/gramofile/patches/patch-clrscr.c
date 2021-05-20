$NetBSD: patch-clrscr.c,v 1.1 2021/05/20 19:24:15 nia Exp $

Include missing header for strlen.

--- clrscr.c.orig	2000-03-28 21:07:25.000000000 +0000
+++ clrscr.c
@@ -13,7 +13,7 @@
 #else
 #include <curses.h>
 #endif
-
+#include <string.h>
 
 void
 header (char *headertext)
