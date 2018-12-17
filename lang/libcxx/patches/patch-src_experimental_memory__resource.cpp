$NetBSD: patch-src_experimental_memory__resource.cpp,v 1.3 2018/12/17 16:07:09 jperkin Exp $

The init_priority attribute isn't supported on SunOS GCC.

--- src/experimental/memory_resource.cpp.orig	2018-07-16 20:01:59.000000000 +0000
+++ src/experimental/memory_resource.cpp
@@ -70,7 +70,7 @@ union ResourceInitHelper {
 };
 
 // Detect if the init_priority attribute is supported.
-#if (defined(_LIBCPP_COMPILER_GCC) && defined(__APPLE__)) \
+#if (defined(_LIBCPP_COMPILER_GCC) && (defined(__APPLE__) || defined(__sun))) \
   || defined(_LIBCPP_COMPILER_MSVC)
 // GCC on Apple doesn't support the init priority attribute,
 // and MSVC doesn't support any GCC attributes.
