$NetBSD: patch-src_experimental_memory__resource.cpp,v 1.1 2018/08/09 14:16:08 jperkin Exp $

The init_priority attribute isn't supported on SunOS GCC.

--- src/experimental/memory_resource.cpp.orig	2018-01-03 16:58:30.000000000 +0000
+++ src/experimental/memory_resource.cpp
@@ -73,7 +73,11 @@ union ResourceInitHelper {
 #if _LIBCPP_STD_VER > 11
 _LIBCPP_SAFE_STATIC
 #endif
+#ifdef __sun
+ResourceInitHelper res_init;
+#else
 ResourceInitHelper res_init  __attribute__((init_priority (101)));
+#endif
 
 } // end namespace
 
