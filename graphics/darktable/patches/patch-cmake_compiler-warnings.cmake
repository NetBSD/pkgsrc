$NetBSD: patch-cmake_compiler-warnings.cmake,v 1.1 2019/03/05 11:19:24 ryoon Exp $

* Disable -Wshadow always to fix build

--- cmake/compiler-warnings.cmake.orig	2018-12-24 09:31:27.000000000 +0000
+++ cmake/compiler-warnings.cmake
@@ -12,14 +12,6 @@ else()
   CHECK_COMPILER_FLAG_AND_ENABLE_IT(-Wformat-security)
 endif()
 
-# cleanup this once we no longer need to support gcc-4.9
-if(NOT (CMAKE_C_COMPILER_ID STREQUAL "GNU" AND CMAKE_C_COMPILER_VERSION VERSION_LESS 5.0))
-  CHECK_C_COMPILER_FLAG_AND_ENABLE_IT(-Wshadow)
-endif()
-if(NOT (CMAKE_CXX_COMPILER_ID STREQUAL "GNU" AND CMAKE_CXX_COMPILER_VERSION VERSION_LESS 5.0))
-  CHECK_CXX_COMPILER_FLAG_AND_ENABLE_IT(-Wshadow)
-endif()
-
 CHECK_COMPILER_FLAG_AND_ENABLE_IT(-Wtype-limits)
 
 CHECK_COMPILER_FLAG_AND_ENABLE_IT(-Wvla)
