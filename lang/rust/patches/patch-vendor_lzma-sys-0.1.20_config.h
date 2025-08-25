$NetBSD: patch-vendor_lzma-sys-0.1.20_config.h,v 1.2 2025/08/25 17:51:13 wiz Exp $

clock_gettime() is available also on NetBSD.

This takes care of this build error:

  cargo:warning=xz-5.2/src/common/mythread.h: In function 'mythread_condtime_set':
  cargo:warning=xz-5.2/src/common/mythread.h:312:9: error: implicit declaration of function 'gettimeofday' [-Wimplicit-function-declaration]
  cargo:warning=  312 |         gettimeofday(&now, NULL);
  cargo:warning=      |         ^~~~~~~~~~~~

which popped up when switching powerpc to using gcc14, but strangely
was not triggered by gcc12 or in-tree gcc.

--- vendor/lzma-sys-0.1.20/config.h.orig	2025-02-11 23:15:56.129312069 +0000
+++ vendor/lzma-sys-0.1.20/config.h
@@ -39,7 +39,7 @@
     #define MYTHREAD_POSIX 1
 #endif
 
-#if defined(__sun)
+#if defined(__sun) || defined(__NetBSD__)
     #define HAVE_CLOCK_GETTIME 1
     #define HAVE_DECL_CLOCK_MONOTONIC 1
 #endif
