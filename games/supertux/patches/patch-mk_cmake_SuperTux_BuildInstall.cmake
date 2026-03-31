$NetBSD: patch-mk_cmake_SuperTux_BuildInstall.cmake,v 1.1 2026/03/31 10:47:13 adam Exp $

On Darwin, don't use app bundle.

--- mk/cmake/SuperTux/BuildInstall.cmake.orig	2026-03-31 08:54:44.486755619 +0000
+++ mk/cmake/SuperTux/BuildInstall.cmake
@@ -22,7 +22,7 @@ if(WIN32 AND NOT UNIX)
   endif()
 
 else()
-  if(${CMAKE_SYSTEM_NAME} MATCHES "Darwin" AND DISABLE_CPACK_BUNDLING)
+  if(FALSE)
 
     set(INFOPLIST_CFBUNDLEEXECUTABLE "supertux2")
 
