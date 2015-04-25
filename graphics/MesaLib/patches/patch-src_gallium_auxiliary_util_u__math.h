$NetBSD: patch-src_gallium_auxiliary_util_u__math.h,v 1.1 2015/04/25 11:19:18 tnn Exp $

The C99 "restrict" keyword is not valid in C++, but most compilers will
understand __restrict.

--- src/gallium/auxiliary/util/u_math.h.orig	2015-03-28 18:20:39.000000000 +0000
+++ src/gallium/auxiliary/util/u_math.h
@@ -531,6 +531,9 @@ unsigned ffs( unsigned u )
 #elif defined(__MINGW32__) || defined(PIPE_OS_ANDROID)
 #define ffs __builtin_ffs
 #define ffsll __builtin_ffsll
+#elif defined(__NetBSD__)
+#include <sys/bitops.h>
+#define ffsll ffs64
 #endif
 
 #endif /* FFS_DEFINED */
@@ -821,6 +824,11 @@ util_bswap16(uint16_t n)
           (n << 8);
 }
 
+#if defined(__cplusplus) && !defined(restrict)
+#define undef_restrict
+#define restrict __restrict
+#endif
+
 static INLINE void*
 util_memcpy_cpu_to_le32(void * restrict dest, const void * restrict src, size_t n)
 {
@@ -839,6 +847,11 @@ util_memcpy_cpu_to_le32(void * restrict 
 #endif
 }
 
+#if defined(undef_restrict)
+#undef undef_restrict
+#undef restrict
+#endif
+
 /**
  * Clamp X to [MIN, MAX].
  * This is a macro to allow float, int, uint, etc. types.
