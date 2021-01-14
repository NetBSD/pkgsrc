$NetBSD: patch-src_Unix_sysdeps.h,v 1.1 2021/01/14 02:47:39 nat Exp $

This makes the idlewait option when NetBSD is emulating a 68k work again.

--- src/Unix/sysdeps.h.orig	2019-04-05 05:12:49.000000000 +0000
+++ src/Unix/sysdeps.h
@@ -117,11 +117,6 @@
 #ifdef HAVE_PTHREADS
 #define USE_PTHREADS_SERVICES
 #endif
-#if EMULATED_68K
-#if defined(__NetBSD__)
-#define USE_CPU_EMUL_SERVICES
-#endif
-#endif
 #ifdef USE_CPU_EMUL_SERVICES
 #undef USE_PTHREADS_SERVICES
 #endif
