$NetBSD: patch-cmake_LLVM.cmake,v 1.1 2025/05/09 06:05:18 adam Exp $

Support LLVM 19.

--- cmake/LLVM.cmake.orig	2025-05-03 06:02:25.986630878 +0000
+++ cmake/LLVM.cmake
@@ -185,8 +185,11 @@ elseif(LLVM_VERSION MATCHES "^17[.]")
 elseif(LLVM_VERSION MATCHES "^18[.]")
   set(LLVM_MAJOR 18)
   set(LLVM_18_0 1)
+elseif(LLVM_VERSION MATCHES "^19[.]")
+  set(LLVM_MAJOR 19)
+  set(LLVM_19_0 1)
 else()
-  message(FATAL_ERROR "LLVM version between 14.0 and 18.0 required, found: ${LLVM_VERSION}")
+  message(FATAL_ERROR "LLVM version between 14.0 and 19.0 required, found: ${LLVM_VERSION}")
 endif()
 
 #############################################################
