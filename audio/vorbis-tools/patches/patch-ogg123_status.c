$NetBSD: patch-ogg123_status.c,v 1.1 2022/03/26 21:33:47 tnn Exp $

for TIOCGWINSZ on SunOS

--- ogg123/status.c.orig	2021-01-02 19:54:35.000000000 +0000
+++ ogg123/status.c
@@ -22,6 +22,7 @@
 #include <stdio.h>
 #include <stdlib.h>
 #include <pthread.h>
+#include <termios.h>
 
 #ifdef HAVE_UNISTD_H
 #include <sys/ioctl.h>
