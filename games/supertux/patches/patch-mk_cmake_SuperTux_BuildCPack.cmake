$NetBSD: patch-mk_cmake_SuperTux_BuildCPack.cmake,v 1.1 2026/03/31 10:47:13 adam Exp $

On Darwin, don't use app bundle.

--- mk/cmake/SuperTux/BuildCPack.cmake.orig	2026-03-31 09:00:50.296352874 +0000
+++ mk/cmake/SuperTux/BuildCPack.cmake
@@ -3,7 +3,7 @@ option(DISABLE_CPACK_BUNDLING "Build an
 include(InstallRequiredSystemLibraries)
 set(DIRS ${CMAKE_CURRENT_BINARY_DIR}/external/tinygettext ${CMAKE_CURRENT_BINARY_DIR}/external/simplesquirrel)
 
-if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin" AND NOT DISABLE_CPACK_BUNDLING)
+if(FALSE)
   set(INFOPLIST_CFBUNDLEEXECUTABLE "SuperTux")
 
   find_package(PNG)
