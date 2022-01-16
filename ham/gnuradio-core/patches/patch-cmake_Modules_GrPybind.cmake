$NetBSD: patch-cmake_Modules_GrPybind.cmake,v 1.1 2022/01/16 18:06:25 tnn Exp $

Disable use of precompiled headers; it doesn't play nice with pkgsrc nor ccache.

--- cmake/Modules/GrPybind.cmake.orig	2022-01-14 15:27:04.000000000 +0000
+++ cmake/Modules/GrPybind.cmake
@@ -158,7 +158,7 @@ target_include_directories(${name}_pytho
 # Precompile the pybind11 header
 # This should speed up building of the python bindings at least in larger modules
 # This functionality is only available in CMake >= 3.16
-if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.16.0")
+if(false AND ${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.16.0")
   target_precompile_headers(
     ${name}_python
     PRIVATE
