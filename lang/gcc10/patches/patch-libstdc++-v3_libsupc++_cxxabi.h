$NetBSD: patch-libstdc++-v3_libsupc++_cxxabi.h,v 1.1 2024/04/01 14:33:58 js Exp $

Nasty hack because ptrdiff_t is missing on QNX with GCC 10 when stddef.h is not
included first.

--- libstdc++-v3/libsupc++/cxxabi.h.orig	2023-07-07 07:08:22.000000000 +0000
+++ libstdc++-v3/libsupc++/cxxabi.h
@@ -58,6 +58,9 @@ namespace __cxxabiv1
   {
 #endif
 
+#ifdef __QNX__
+  typedef __PTRDIFF_TYPE__ ptrdiff_t;
+#endif
   typedef __cxa_cdtor_return_type (*__cxa_cdtor_type)(void *);
 
   // Allocate array.
