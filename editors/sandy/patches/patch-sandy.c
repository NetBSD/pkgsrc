$NetBSD: patch-sandy.c,v 1.2 2017/07/06 11:31:16 wiedi Exp $

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
