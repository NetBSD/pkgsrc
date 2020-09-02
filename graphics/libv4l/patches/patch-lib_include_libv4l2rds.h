$NetBSD: patch-lib_include_libv4l2rds.h,v 1.1 2020/09/02 09:54:33 ryoon Exp $

--- lib/include/libv4l2rds.h.orig	2017-01-22 17:33:34.000000000 +0000
+++ lib/include/libv4l2rds.h
@@ -24,7 +24,7 @@
 #include <stdbool.h>
 #include <stdint.h>
 
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
