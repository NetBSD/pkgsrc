$NetBSD: patch-src_common_byte__stream.cpp,v 1.1 2023/11/14 17:57:41 nia Exp $

NetBSD (and more POSIX platforms) support.

--- src/common/byte_stream.cpp.orig	2023-08-12 04:46:09.000000000 +0000
+++ src/common/byte_stream.cpp
@@ -27,7 +27,7 @@
 
 #ifdef _MSC_VER
 #include <malloc.h>
-#else
+#elif defined(__linux__) || defined(__sun)
 #include <alloca.h>
 #endif
 
