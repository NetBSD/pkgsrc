$NetBSD: patch-Source_CMakeInstallDestinations.cmake,v 1.1 2026/03/26 09:01:10 adam Exp $

On Darwin, don't make application bundle.

--- Source/CMakeInstallDestinations.cmake.orig	2026-03-24 11:09:19.944351057 +0000
+++ Source/CMakeInstallDestinations.cmake
@@ -35,7 +35,7 @@ set_property(CACHE CMake_INSTALL_INFIX P
   )
 mark_as_advanced(CMake_INSTALL_INFIX)
 
-if(APPLE AND BUILD_QtDialog)
+if(FALSE AND BUILD_QtDialog)
   set(CMake_INSTALL_APP_DIR "CMake.app/Contents")
   set(CMake_INSTALL_APP_DIR_SLASH "${CMake_INSTALL_APP_DIR}/")
 else()
