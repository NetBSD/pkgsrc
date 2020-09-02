$NetBSD: patch-lib_include_libv4lconvert.h,v 1.1 2020/09/02 09:54:33 ryoon Exp $

--- lib/include/libv4lconvert.h.orig	2017-01-22 17:33:34.000000000 +0000
+++ lib/include/libv4lconvert.h
@@ -28,7 +28,7 @@
 #include <linux/ioctl.h>
 #endif
 
-#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__)
+#if defined(__FreeBSD__) || defined(__FreeBSD_kernel__) || defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/time.h>
 #include <sys/types.h>
 #include <sys/ioctl.h>
@@ -36,7 +36,7 @@
 
 /* end broken header workaround includes */
 
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
