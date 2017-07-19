$NetBSD: patch-Modules_Platform_UnixPaths.cmake,v 1.1 2017/07/19 17:44:34 adam Exp $

Patch in pkgsrc paths for finding stuff.

--- Modules/Platform/UnixPaths.cmake.orig	2017-07-18 15:22:54.000000000 +0000
+++ Modules/Platform/UnixPaths.cmake
@@ -23,7 +23,7 @@ get_filename_component(_CMAKE_INSTALL_DI
 # search types.
 list(APPEND CMAKE_SYSTEM_PREFIX_PATH
   # Standard
-  /usr/local /usr /
+  @LOCALBASE@ /usr/local /usr /
 
   # CMake install location
   "${_CMAKE_INSTALL_DIR}"
@@ -43,20 +43,20 @@ endif()
 
 # Non "standard" but common install prefixes
 list(APPEND CMAKE_SYSTEM_PREFIX_PATH
-  /usr/X11R6
-  /usr/pkg
+  @X11BASE@ 
+  @LOCALBASE@
   /opt
   )
 
 # List common include file locations not under the common prefixes.
 list(APPEND CMAKE_SYSTEM_INCLUDE_PATH
   # X11
-  /usr/include/X11
+  @X11BASE@/include
   )
 
 list(APPEND CMAKE_SYSTEM_LIBRARY_PATH
   # X11
-  /usr/lib/X11
+  @X11BASE@/lib
   )
 
 list(APPEND CMAKE_PLATFORM_IMPLICIT_LINK_DIRECTORIES
