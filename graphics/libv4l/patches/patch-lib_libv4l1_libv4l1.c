$NetBSD: patch-lib_libv4l1_libv4l1.c,v 1.1 2020/09/02 09:54:33 ryoon Exp $

--- lib/libv4l1/libv4l1.c.orig	2017-01-22 17:33:34.000000000 +0000
+++ lib/libv4l1/libv4l1.c
@@ -58,7 +58,7 @@
 #include <sys/types.h>
 #include <sys/mman.h>
 #include "../libv4lconvert/libv4lsyscall-priv.h"
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/videoio.h>
 #else
 #include <linux/videodev2.h>
