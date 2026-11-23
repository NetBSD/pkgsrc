$NetBSD: patch-mk_cmake_SuperTux_BuildCPack.cmake,v 1.2 2026/11/23 11:41:36 adam Exp $

On Darwin, don't use app bundle.

--- mk/cmake/SuperTux/BuildCPack.cmake.orig	2026-11-22 04:50:58.000000000 +0000
+++ mk/cmake/SuperTux/BuildCPack.cmake
@@ -2,7 +2,7 @@ option(DISABLE_CPACK_BUNDLING "Build an
 
 include(InstallRequiredSystemLibraries)
 
-if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin" AND NOT DISABLE_CPACK_BUNDLING)
+if(FALSE)
   set(INFOPLIST_CFBUNDLEEXECUTABLE "SuperTux")
 
   install(RUNTIME_DEPENDENCY_SET supertux2_deps LIBRARY DESTINATION "MacOS")
