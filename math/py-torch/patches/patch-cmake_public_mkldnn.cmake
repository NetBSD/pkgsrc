$NetBSD: patch-cmake_public_mkldnn.cmake,v 1.1 2025/01/21 13:36:49 ryoon Exp $

* Fix MLKDNN related undefined symbols.

--- cmake/public/mkldnn.cmake.orig	2025-01-19 14:42:24.569420877 +0000
+++ cmake/public/mkldnn.cmake
@@ -4,7 +4,7 @@ if(CPU_AARCH64)
   include(${CMAKE_CURRENT_LIST_DIR}/ComputeLibrary.cmake)
 endif()
 
-find_package(MKLDNN QUIET)
+find_package(MKLDNN REQUIRED)
 
 if(NOT TARGET caffe2::mkldnn)
   add_library(caffe2::mkldnn INTERFACE IMPORTED)
