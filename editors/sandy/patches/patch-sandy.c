$NetBSD: patch-sandy.c,v 1.1 2017/07/06 09:09:02 wiedi Exp $

Needs include for TIOCGWINSZ on SunOS
--- sandy.c.orig	2011-04-01 16:05:58.000000000 +0000
+++ sandy.c
@@ -14,6 +14,10 @@
 #include <string.h>
 #include <curses.h>
 
+#if defined(__sun)
+#include <sys/termios.h>
+#endif
+
 /* Defines */
 #ifndef PIPESIZ /* This is POSIX magic */
 #define PIPESIZ 4096
