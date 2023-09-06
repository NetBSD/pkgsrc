$NetBSD: patch-build_cmake_exports.cmake,v 1.3 2023/09/06 14:48:01 ryoon Exp $

Don't use --version-script on SunOS.

--- build/cmake/exports.cmake.orig	2023-08-25 19:06:01.000000000 +0000
+++ build/cmake/exports.cmake
@@ -68,7 +68,7 @@ function(setup_exports_target)
                    APPEND_STRING
                    PROPERTY LINK_FLAGS "${aom_sym_file}")
     endif()
-  else()
+  elseif(NOT CMAKE_SYSTEM_NAME STREQUAL "SunOS")
     set_property(TARGET aom
                  APPEND_STRING
                  PROPERTY LINK_FLAGS "-Wl,--version-script,${aom_sym_file}")
