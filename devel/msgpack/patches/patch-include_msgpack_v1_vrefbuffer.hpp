$NetBSD: patch-include_msgpack_v1_vrefbuffer.hpp,v 1.2 2018/06/01 07:55:43 adam Exp $

NetBSD and FreeBSD fix.

--- include/msgpack/v1/vrefbuffer.hpp.orig	2017-09-03 19:45:31.891730579 +0000
+++ include/msgpack/v1/vrefbuffer.hpp
@@ -22,7 +22,7 @@
 #endif
 #endif // defined(_MSC_VER)
 
-#if defined(unix) || defined(__unix) || defined(__APPLE__) || defined(__OpenBSD__)
+#if defined(unix) || defined(__unix) || defined(__APPLE__) || defined(__OpenBSD__) || defined(__QNX__) || defined(__QNXTO__) || defined(__NetBSD__) || defined(__FreeBSD__)
 #include <sys/uio.h>
 #else
 struct iovec {
