$NetBSD: patch-cmake_Modules_GrPybind.cmake,v 1.2 2022/10/09 07:56:09 adam Exp $

Disable use of precompiled headers; it doesn't play nice with pkgsrc nor ccache.

--- cmake/Modules/GrPybind.cmake.orig	2022-09-16 15:51:17.000000000 +0000
+++ cmake/Modules/GrPybind.cmake
@@ -176,7 +176,7 @@ macro(GR_PYBIND_MAKE_CHECK_HASH name upd
     # Precompile the pybind11 header
     # This should speed up building of the python bindings at least in larger modules
     # This functionality is only available in CMake >= 3.16
-    if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.16.0")
+    if(FALSE AND ${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.16.0")
         target_precompile_headers(
             ${name}_python
             PRIVATE
