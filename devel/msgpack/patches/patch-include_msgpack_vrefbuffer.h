$NetBSD: patch-include_msgpack_vrefbuffer.h,v 1.3 2020/04/11 13:39:29 adam Exp $

FreeBSD fix.

--- include/msgpack/vrefbuffer.h.orig	2019-12-10 03:33:32.000000000 +0000
+++ include/msgpack/vrefbuffer.h
@@ -13,7 +13,7 @@
 #include "zone.h"
 #include <stdlib.h>
 
-#if defined(unix) || defined(__unix) || defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__QNX__) || defined(__QNXTO__) || defined(__HAIKU__)
+#if defined(unix) || defined(__unix) || defined(__linux__) || defined(__APPLE__) || defined(__FreeBSD__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__QNX__) || defined(__QNXTO__) || defined(__HAIKU__)
 #include <sys/uio.h>
 #else
 struct iovec {
