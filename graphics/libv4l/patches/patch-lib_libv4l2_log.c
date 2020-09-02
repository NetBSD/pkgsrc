$NetBSD: patch-lib_libv4l2_log.c,v 1.1 2020/09/02 09:54:33 ryoon Exp $

--- lib/libv4l2/log.c.orig	2017-01-22 17:33:34.000000000 +0000
+++ lib/libv4l2/log.c
@@ -28,7 +28,7 @@
 #include <string.h>
 #include <errno.h>
 #include "../libv4lconvert/libv4lsyscall-priv.h"
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
