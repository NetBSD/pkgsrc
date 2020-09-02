$NetBSD: patch-lib_libv4l-mplane_libv4l-mplane.c,v 1.1 2020/09/02 09:54:33 ryoon Exp $

--- lib/libv4l-mplane/libv4l-mplane.c.orig	2017-01-22 17:33:34.000000000 +0000
+++ lib/libv4l-mplane/libv4l-mplane.c
@@ -26,7 +26,7 @@
 #include <unistd.h>
 #include <sys/syscall.h>
 
-#if defined(__OpenBSD__)
+#if defined(__OpenBSD__) || defined(__NetBSD__)
 #include <sys/videoio.h>
 #include <sys/ioctl.h>
 #else
