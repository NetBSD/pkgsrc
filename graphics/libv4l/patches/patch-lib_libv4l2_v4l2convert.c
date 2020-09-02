$NetBSD: patch-lib_libv4l2_v4l2convert.c,v 1.1 2020/09/02 09:54:33 ryoon Exp $

--- lib/libv4l2/v4l2convert.c.orig	2017-01-22 17:33:34.000000000 +0000
+++ lib/libv4l2/v4l2convert.c
@@ -36,7 +36,7 @@
 #include <string.h>
 #include <sys/ioctl.h>
 #include <sys/mman.h>
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
