$NetBSD: patch-lib_cximage-6.0_CxImage_ximage.h,v 1.1 2015/11/17 14:56:07 jmcneill Exp $

--- lib/cximage-6.0/CxImage/ximage.h.orig	2015-10-19 06:31:15.000000000 +0000
+++ lib/cximage-6.0/CxImage/ximage.h
@@ -54,6 +54,9 @@
 
 #ifdef _LINUX
 #define _XOPEN_SOURCE
+#if defined(__NetBSD__)
+#define _NETBSD_SOURCE
+#endif
 #include <unistd.h>
 #include <arpa/inet.h>
 #endif
