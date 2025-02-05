$NetBSD: patch-gcc_ginclude_stddef.h,v 1.1 2025/02/05 16:30:36 adam Exp $

Support Darwin/aarch64, from https://github.com/Homebrew/formula-patches.

--- gcc/ginclude/stddef.h
+++ gcc/ginclude/stddef.h
@@ -428,9 +428,8 @@ typedef struct {
   /* _Float128 is defined as a basic type, so max_align_t must be
      sufficiently aligned for it.  This code must work in C++, so we
      use __float128 here; that is only available on some
-     architectures, but only on i386 is extra alignment needed for
-     __float128.  */
-#ifdef __i386__
+     architectures.  */
+#if defined(__i386__) || (__APPLE__ && __aarch64__)
   __float128 __max_align_f128 __attribute__((__aligned__(__alignof(__float128))));
 #endif
 } max_align_t;
