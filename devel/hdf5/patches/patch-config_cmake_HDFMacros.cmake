$NetBSD: patch-config_cmake_HDFMacros.cmake,v 1.1 2025/03/05 06:24:20 adam Exp $

On Darwin, do not install binaries with @rpath.

--- config/cmake/HDFMacros.cmake.orig	2025-03-03 17:00:50.920692184 +0000
+++ config/cmake/HDFMacros.cmake
@@ -466,7 +466,7 @@ macro (HDF_DIR_PATHS package_prefix)
   # add the automatically determined parts of the RPATH
   # which point to directories outside the build tree to the install RPATH
   set (CMAKE_BUILD_WITH_INSTALL_RPATH ON)
-  if (APPLE)
+  if (FALSE)
     set (CMAKE_INSTALL_NAME_DIR "@rpath")
     set (CMAKE_INSTALL_RPATH
         "@executable_path/../${${package_prefix}_INSTALL_LIB_DIR}"
