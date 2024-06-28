$NetBSD: patch-include_msgpack_vrefbuffer.h,v 1.4 2024/06/28 17:35:09 adam Exp $

FreeBSD fix.

--- include/msgpack/vrefbuffer.h.orig	2023-04-26 14:20:34.000000000 +0000
+++ include/msgpack/vrefbuffer.h
@@ -14,7 +14,7 @@
 #include <stdlib.h>
 #include <assert.h>
 
-#if defined(unix) || defined(__unix) || defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__QNX__) || defined(__QNXTO__) || defined(__HAIKU__)
+#if defined(unix) || defined(__unix) || defined(__linux__) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__NetBSD__) || defined(__QNX__) || defined(__QNXTO__) || defined(__HAIKU__) || defined(__FreeBSD__)
 #include <sys/uio.h>
 typedef struct iovec msgpack_iovec;
 #else
