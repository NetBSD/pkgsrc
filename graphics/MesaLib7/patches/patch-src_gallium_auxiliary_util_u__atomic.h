$NetBSD: patch-src_gallium_auxiliary_util_u__atomic.h,v 1.1 2015/04/05 17:01:37 tnn Exp $

Add atomic operations for PowerPC platforms without GCC >= 4.1. This
should probably be sent to the upstream.

--- src/gallium/auxiliary/util/u_atomic.h.orig	2014-01-10 06:56:00.000000000 +0000
+++ src/gallium/auxiliary/util/u_atomic.h
@@ -31,6 +31,8 @@
 #define PIPE_ATOMIC_ASM_GCC_X86
 #elif (defined(PIPE_CC_GCC) && defined(PIPE_ARCH_X86_64))
 #define PIPE_ATOMIC_ASM_GCC_X86_64
+#elif (defined(PIPE_CC_GCC) && defined(PIPE_ARCH_PPC))
+#define PIPE_ATOMIC_ASM_GCC_PPC
 #elif defined(PIPE_CC_GCC) && (PIPE_CC_GCC_VERSION >= 401)
 #define PIPE_ATOMIC_GCC_INTRINSIC
 #else
@@ -131,6 +133,90 @@ p_atomic_cmpxchg(int32_t *v, int32_t old
 #endif
 
 
+#if defined(PIPE_ATOMIC_ASM_GCC_PPC)
+
+#define PIPE_ATOMIC "GCC ppc assembly"
+
+#ifdef __cplusplus
+extern "C" {
+#endif
+
+#define p_atomic_set(_v, _i) (*(_v) = (_i))
+#define p_atomic_read(_v) (*(_v))
+
+static INLINE boolean
+p_atomic_dec_zero(int32_t *v)
+{
+    int32_t c;
+
+    __asm__ __volatile__(
+        "1: lwarx   %0,0,%1\n"
+        "   addic   %0,%0,-1\n"
+        "   stwcx.  %0,0,%1\n"
+        "   bne-    1b"
+        : "=&r" (c)
+        : "r" (v)
+        : "cc", "memory");
+
+    return c != 0;
+}
+
+static INLINE void
+p_atomic_inc(int32_t *v)
+{
+    int32_t c;
+
+    __asm__ __volatile__(
+        "1: lwarx   %0,0,%1\n"
+        "   addic   %0,%0,1\n"
+        "   stwcx.  %0,0,%1\n"
+        "   bne-    1b"
+        : "=&r" (c)
+        : "r" (v)
+        : "cc", "memory");
+}
+
+static INLINE void
+p_atomic_dec(int32_t *v)
+{
+    int32_t c;
+
+    __asm__ __volatile__(
+        "1: lwarx   %0,0,%1\n"
+        "   addic   %0,%0,-1\n"
+        "   stwcx.  %0,0,%1\n"
+        "   bne-    1b"
+        : "=&r" (c)
+        : "r" (v)
+        : "cc", "memory");
+}
+
+static INLINE int32_t
+p_atomic_cmpxchg(int32_t *v, int32_t old, int32_t _new)
+{
+    int32_t oldval;
+
+    __asm__ __volatile__(
+        "1: lwarx  %0,0,%2\n"
+        "   cmpw   0,%0,%3\n"
+        "   bne-   2f\n"
+        "   stwcx. %4,0,%2\n"
+        "   bne-   1b\n"
+        "2:\n"
+        : "=&r" (oldval), "+m" (*v)
+        : "r" (v), "r" (old), "r" (_new)
+        : "cc", "memory");
+
+    return oldval;
+}
+
+#ifdef __cplusplus
+}
+#endif
+
+#endif /* PIPE_ATOMIC_ASM_PPC */
+
+
 
 /* Implementation using GCC-provided synchronization intrinsics
  */
