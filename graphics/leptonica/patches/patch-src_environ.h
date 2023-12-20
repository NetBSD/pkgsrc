$NetBSD: patch-src_environ.h,v 1.1 2023/12/20 10:31:34 nros Exp $

* Illumos gcc defines __STDC_VERSION__ in C++ mode,
  this causes problems for leptonica C++ consumers
  when gcc 12 is used. In gcc 12 atomic_int is not
  defined in stdatomic.h in C++ mode. 
  Make sure this path in not chosen in C++ mode,
  like gcc on GNU Linux, NetBSD etc. 

--- src/environ.h.orig	2023-01-26 06:12:24.000000000 +0000
+++ src/environ.h
@@ -65,7 +65,7 @@ typedef unsigned int uintptr_t;
 
 #endif /* _MSC_VER */
 
-#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L) && !defined(__STDC_NO_ATOMICS__)
+#if defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 201112L) && !defined(__STDC_NO_ATOMICS__) && !defined(__cplusplus)
 #include <stdatomic.h>
 typedef atomic_int l_atomic;
 #else
