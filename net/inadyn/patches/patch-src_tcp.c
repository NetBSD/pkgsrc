$NetBSD: patch-src_tcp.c,v 1.3 2019/12/13 21:52:04 dmcmahill Exp $

pull in time.h for struct timeval

--- src/tcp.c.orig	2017-12-27 07:46:43.000000000 -0500
+++ src/tcp.c
@@ -30,4 +30,5 @@
 #include <stdlib.h>
 #include <string.h>
+#include <time.h>
 #include <unistd.h>
 #include <sys/ioctl.h>
