$NetBSD: patch-src_gallium_auxiliary_util_u__math.h,v 1.4 2015/09/26 08:45:02 tnn Exp $

The C99 "restrict" keyword is not valid in C++, but most compilers will
understand __restrict.

--- src/gallium/auxiliary/util/u_math.h.orig	2015-09-11 17:41:47.000000000 +0000
+++ src/gallium/auxiliary/util/u_math.h
@@ -709,6 +712,11 @@ util_bswap16(uint16_t n)
           (n << 8);
 }
 
+#if defined(__cplusplus) && !defined(restrict)
+#define undef_restrict
+#define restrict __restrict
+#endif
+
 static inline void*
 util_memcpy_cpu_to_le32(void * restrict dest, const void * restrict src, size_t n)
 {
@@ -727,6 +735,11 @@ util_memcpy_cpu_to_le32(void * restrict 
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
