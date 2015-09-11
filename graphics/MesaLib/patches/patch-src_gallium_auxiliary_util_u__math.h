$NetBSD: patch-src_gallium_auxiliary_util_u__math.h,v 1.3 2015/09/11 00:03:36 tnn Exp $

The C99 "restrict" keyword is not valid in C++, but most compilers will
understand __restrict.

--- src/gallium/auxiliary/util/u_math.h.orig	2015-09-10 17:40:30.000000000 +0000
+++ src/gallium/auxiliary/util/u_math.h
@@ -401,6 +401,9 @@ unsigned ffs( unsigned u )
 #if defined(__MINGW32__) || defined(PIPE_OS_ANDROID) || \
     defined(HAVE___BUILTIN_FFSLL)
 #define ffsll __builtin_ffsll
+#elif defined(__NetBSD__)
+#include <sys/bitops.h>
+#define ffsll ffs64
 #endif
 
 #endif /* FFSLL_DEFINED */
@@ -690,6 +693,11 @@ util_bswap16(uint16_t n)
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
@@ -708,6 +716,11 @@ util_memcpy_cpu_to_le32(void * restrict 
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
