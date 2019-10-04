$NetBSD: patch-libdeflate_compiler__gcc.h,v 1.3 2019/10/04 18:08:07 nia Exp $

Avoid conflicts due to changing the prototypes of bswap32 and co.

--- libdeflate/compiler_gcc.h.orig	2017-01-24 17:51:01.000000000 +0000
+++ libdeflate/compiler_gcc.h
@@ -93,6 +93,9 @@
 #  define CPU_IS_LITTLE_ENDIAN() (__BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__)
 #endif
 
+#ifdef __NetBSD__
+#include <sys/endian.h>
+#else
 #if GCC_PREREQ(4, 8) || __has_builtin(__builtin_bswap16)
 #  define bswap16	__builtin_bswap16
 #endif
@@ -104,6 +107,7 @@
 #if GCC_PREREQ(4, 3) || __has_builtin(__builtin_bswap64)
 #  define bswap64	__builtin_bswap64
 #endif
+#endif
 
 #if defined(__x86_64__) || defined(__i386__) || defined(__ARM_FEATURE_UNALIGNED)
 #  define UNALIGNED_ACCESS_IS_FAST 1
