$NetBSD: patch-client_cd-util.c,v 1.3 2026/04/26 14:48:56 vins Exp $

SunOS requires sys/termios.h

--- client/cd-util.c.orig	2016-07-27 13:49:36.000000000 +0000
+++ client/cd-util.c
@@ -27,6 +27,9 @@
 #ifdef HAVE_PWD_H
 #include <pwd.h>
 #endif
+#ifdef __sun
+#include <sys/termios.h>
+#endif
 #include <stdlib.h>
 #include <stdio.h>
 #include <sys/ioctl.h>
