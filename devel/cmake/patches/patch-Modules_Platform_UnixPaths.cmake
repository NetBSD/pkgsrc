$NetBSD: patch-Modules_Platform_UnixPaths.cmake,v 1.3 2026/07/16 11:14:00 adam Exp $

Patch in pkgsrc paths for finding stuff.

--- Modules/Platform/UnixPaths.cmake.orig	2026-07-09 17:24:15.000000000 +0000
+++ Modules/Platform/UnixPaths.cmake
@@ -37,7 +37,7 @@ unset(_cmake_running_in_build_tree)
 # synchronized
 list(APPEND CMAKE_SYSTEM_PREFIX_PATH
   # Standard
-  /usr/local /usr /
+  @LOCALBASE@ /usr/local /usr /
   )
 if(_CMAKE_INSTALL_DIR)
   list(APPEND CMAKE_SYSTEM_PREFIX_PATH
@@ -61,20 +61,20 @@ _cmake_record_install_prefix()
 
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
