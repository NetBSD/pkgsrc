$NetBSD: patch-sandy.c,v 1.3 2019/06/08 10:40:58 rillig Exp $

Needs include for TIOCGWINSZ

--- sandy.c.orig	2011-04-01 16:05:58.000000000 +0000
+++ sandy.c
@@ -14,6 +14,8 @@
 #include <string.h>
 #include <curses.h>
 
+#include <termios.h>
+
 /* Defines */
 #ifndef PIPESIZ /* This is POSIX magic */
 #define PIPESIZ 4096
