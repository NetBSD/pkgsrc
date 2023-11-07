$NetBSD: patch-share_cmake_utils_CppVersion.cmake,v 1.1 2023/11/07 20:29:25 nros Exp $

Use extensions for alloca on NetBSD

--- share/cmake/utils/CppVersion.cmake.orig	2023-11-07 20:06:12.390306361 +0000
+++ share/cmake/utils/CppVersion.cmake
@@ -75,4 +75,4 @@ endif()
 set(CMAKE_CXX_STANDARD_REQUIRED ON)
 
 # Disable any compiler specific C++ extensions.
-set(CMAKE_CXX_EXTENSIONS OFF)
+set(CMAKE_CXX_EXTENSIONS ON)
