$NetBSD: patch-src_qdoc_cmake_QDocConfiguration.cmake,v 1.1 2026/05/28 07:01:21 adam Exp $

Support LLVM 22.

--- src/qdoc/cmake/QDocConfiguration.cmake.orig	2026-05-12 13:04:33.432233380 +0000
+++ src/qdoc/cmake/QDocConfiguration.cmake
@@ -8,7 +8,7 @@ set(QDOC_MINIMUM_CLANG_VERSION "17")
 
 # List of explicitly supported Clang versions for QDoc
 set(QDOC_SUPPORTED_CLANG_VERSIONS
-    "21.1" "20.1" "19.1" "18.1" "17.0.6"
+    "22.1" "21.1" "20.1" "19.1" "18.1" "17.0.6"
 )
 
 # Check for QDoc coverage dependencies
