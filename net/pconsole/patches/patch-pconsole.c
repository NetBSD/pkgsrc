$NetBSD: patch-pconsole.c,v 1.1 2017/07/03 11:55:30 wiedi Exp $

need termios.h for TIOCSTI on SunOS
--- pconsole.c.orig	2001-04-09 08:51:49.000000000 +0000
+++ pconsole.c
@@ -38,6 +38,10 @@
 #include <sys/ioctl.h>
 #endif
 
+#if defined(__sun)
+#include <sys/termios.h>
+#endif
+
 #define KEY_CTRL(x)		((x) - 'A' + 1)
 
 int flags = FLAGS_ECHO;
