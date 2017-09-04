$NetBSD: patch-include_msgpack_vrefbuffer.h,v 1.1 2017/09/04 15:58:05 joerg Exp $

--- include/msgpack/vrefbuffer.h.orig	2017-09-03 19:45:34.429664800 +0000
+++ include/msgpack/vrefbuffer.h
@@ -13,7 +13,7 @@
 #include "zone.h"
 #include <stdlib.h>
 
-#if defined(unix) || defined(__unix) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__QNXTO__)
+#if defined(unix) || defined(__unix) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__QNXTO__) || defined(__NetBSD__) || defined(__FreeBSD__)
 #include <sys/uio.h>
 #else
 struct iovec {
