$NetBSD: patch-src_utils.cpp,v 1.1 2012/06/10 11:54:44 obache Exp $

* `function not inlinable' with gcc-4.1.2 -O2 on NetBSD-5.1.2.

--- src/utils.cpp.orig	2012-04-12 15:46:14.000000000 +0000
+++ src/utils.cpp
@@ -408,7 +408,7 @@ namespace {
 
 #else   // defined(_MSC_VER)
 
-#define FORCE_INLINE __attribute__((always_inline))
+#define FORCE_INLINE inline __attribute__((always_inline))
 
 inline uint32_t rotl32 ( uint32_t x, uint8_t r ) {
   return (x << r) | (x >> (32 - r));
