$NetBSD: patch-libstdc++-v3_libsupc++_cxxabi_init_exception.h,v 1.1 2024/04/01 14:33:58 js Exp $

--- libstdc++-v3/libsupc++/cxxabi_init_exception.h.orig	2023-07-07 07:08:22.000000000 +0000
+++ libstdc++-v3/libsupc++/cxxabi_init_exception.h
@@ -54,6 +54,9 @@ namespace std
 
 namespace __cxxabiv1
 {
+#ifdef __QNX__
+  using std::size_t;
+#endif
   struct __cxa_refcounted_exception;
 
   extern "C"
