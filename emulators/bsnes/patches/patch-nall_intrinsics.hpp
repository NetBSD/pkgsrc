$NetBSD: patch-nall_intrinsics.hpp,v 1.1 2020/10/20 12:21:19 nia Exp $

Use standard bits from endian.h.

Fixes building on NetBSD/aarch64.

--- nall/intrinsics.hpp.orig	2020-03-03 10:56:48.000000000 +0000
+++ nall/intrinsics.hpp
@@ -159,10 +159,14 @@ namespace nall {
 
 namespace nall {
 
-#if (defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN) && __BYTE_ORDER == __LITTLE_ENDIAN) || defined(__LITTLE_ENDIAN__) || defined(__i386__) || defined(__amd64__) || defined(_M_IX86) || defined(_M_AMD64)
+#if (defined(__BYTE_ORDER) && defined(__LITTLE_ENDIAN) && __BYTE_ORDER == __LITTLE_ENDIAN) || \
+    (defined(BYTE_ORDER) && defined(LITTLE_ENDIAN) && BYTE_ORDER == LITTLE_ENDIAN) || \
+    defined(__LITTLE_ENDIAN__) || defined(__i386__) || defined(__amd64__) || defined(_M_IX86) || defined(_M_AMD64)
   #define ENDIAN_LSB
   constexpr auto endian() -> Endian { return Endian::LSB; }
-#elif (defined(__BYTE_ORDER) && defined(__BIG_ENDIAN) && __BYTE_ORDER == __BIG_ENDIAN) || defined(__BIG_ENDIAN__) || defined(__powerpc__) || defined(_M_PPC)
+#elif (defined(__BYTE_ORDER) && defined(__BIG_ENDIAN) && __BYTE_ORDER == __BIG_ENDIAN) || \
+    (defined(BYTE_ORDER) && defined(BIG_ENDIAN) && BYTE_ORDER == BIG_ENDIAN) || \
+    defined(__BIG_ENDIAN__) || defined(__powerpc__) || defined(_M_PPC)
   #define ENDIAN_MSB
   constexpr auto endian() -> Endian { return Endian::MSB; }
 #else
