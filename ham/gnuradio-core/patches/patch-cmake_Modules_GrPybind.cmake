$NetBSD: patch-cmake_Modules_GrPybind.cmake,v 1.3 2025/02/27 13:49:51 adam Exp $

Disable use of precompiled headers; it doesn't play nice with pkgsrc nor ccache.

--- cmake/Modules/GrPybind.cmake.orig	2022-09-16 15:51:17.000000000 +0000
+++ cmake/Modules/GrPybind.cmake
@@ -176,7 +176,7 @@ macro(GR_PYBIND_MAKE_CHECK_HASH name upd
     # Precompile the pybind11 header
     # This should speed up building of the python bindings at least in larger modules
     # This functionality is only available in CMake >= 3.16
-    if(${CMAKE_VERSION} VERSION_GREATER_EQUAL "3.16.0")
+    if(FALSE)
         target_precompile_headers(
             ${name}_python
             PRIVATE
