$NetBSD: patch-build_cmake_exports.cmake,v 1.1 2018/10/23 17:30:21 jperkin Exp $

Don't use --version-script on SunOS.

--- build/cmake/exports.cmake.orig	2018-10-01 03:20:05.000000000 +0000
+++ build/cmake/exports.cmake
@@ -55,7 +55,7 @@ function(setup_exports_target)
 
     # TODO(tomfinegan): Sort out the import lib situation and flags for MSVC.
 
-  else()
+  elseif(NOT CMAKE_SYSTEM_NAME STREQUAL "SunOS")
     set_property(TARGET aom APPEND_STRING
                  PROPERTY LINK_FLAGS "-Wl,--version-script,${aom_sym_file}")
   endif()
