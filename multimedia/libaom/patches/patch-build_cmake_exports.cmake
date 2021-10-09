$NetBSD: patch-build_cmake_exports.cmake,v 1.2 2021/10/09 14:47:24 nia Exp $

Don't use --version-script on SunOS.

--- build/cmake/exports.cmake.orig	2021-10-09 07:54:04.000000000 +0000
+++ build/cmake/exports.cmake
@@ -66,7 +66,7 @@ function(setup_exports_target)
 
     # TODO(tomfinegan): Sort out the import lib situation and flags for MSVC.
 
-  else()
+  elseif(NOT CMAKE_SYSTEM_NAME STREQUAL "SunOS")
     set_property(TARGET aom
                  APPEND_STRING
                  PROPERTY LINK_FLAGS "-Wl,--version-script,${aom_sym_file}")
