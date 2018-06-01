$NetBSD: patch-include_msgpack_vrefbuffer.h,v 1.2 2018/06/01 07:55:43 adam Exp $

FreeBSD fix.

--- include/msgpack/vrefbuffer.h.orig	2018-04-09 13:56:00.000000000 +0000
+++ include/msgpack/vrefbuffer.h
@@ -13,7 +13,7 @@
 #include "zone.h"
 #include <stdlib.h>
 
-#if defined(unix) || defined(__unix) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__QNX__) || defined(__QNXTO__)
+#if defined(unix) || defined(__unix) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__QNX__) || defined(__QNXTO__) || defined(__FreeBSD__)
 #include <sys/uio.h>
 #else
 struct iovec {
