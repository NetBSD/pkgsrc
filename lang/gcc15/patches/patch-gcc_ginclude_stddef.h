$NetBSD: patch-gcc_ginclude_stddef.h,v 1.1 2026/07/19 11:17:44 adam Exp $

Support Darwin/aarch64.
https://github.com/Homebrew/homebrew-core/blob/main/Patches/gcc/gcc-15.3.0.diff

--- gcc/ginclude/stddef.h.orig	2026-06-12 06:09:06.509664884 +0000
+++ gcc/ginclude/stddef.h
@@ -443,9 +443,8 @@ typedef struct {
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
