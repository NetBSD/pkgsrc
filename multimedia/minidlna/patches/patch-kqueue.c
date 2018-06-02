$NetBSD: patch-kqueue.c,v 1.1 2018/06/02 12:53:10 jmcneill Exp $

--- kqueue.c.orig	2018-05-04 23:11:25.000000000 +0000
+++ kqueue.c
@@ -28,6 +28,7 @@
 
 #include <sys/types.h>
 #include <sys/event.h>
+#include <sys/time.h>
 #include <assert.h>
 #include <errno.h>
 #include <stdlib.h>
