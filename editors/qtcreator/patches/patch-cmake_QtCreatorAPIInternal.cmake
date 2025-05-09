$NetBSD: patch-cmake_QtCreatorAPIInternal.cmake,v 1.1 2025/05/09 05:57:08 adam Exp $

Disable application bundle.

--- cmake/QtCreatorAPIInternal.cmake.orig	2025-03-11 12:27:32.000000000 +0000
+++ cmake/QtCreatorAPIInternal.cmake
@@ -43,7 +43,7 @@ endif()
 # Setup path handling
 #
 
-if (APPLE)
+if (FALSE)
   set(_IDE_APP_PATH ".")
   set(_IDE_APP_TARGET "${IDE_DISPLAY_NAME}")
 
@@ -197,7 +197,7 @@ endfunction()
 
 function(qtc_add_link_flags_no_undefined target)
   # needs CheckLinkerFlags
-  if (CMAKE_VERSION VERSION_GREATER_EQUAL 3.18 AND NOT MSVC AND NOT APPLE)
+  if (CMAKE_VERSION VERSION_GREATER_EQUAL 3.18 AND NOT MSVC)
     set(no_undefined_flag "-Wl,--no-undefined")
     check_linker_flag(CXX ${no_undefined_flag} QTC_LINKER_SUPPORTS_NO_UNDEFINED)
     if (NOT QTC_LINKER_SUPPORTS_NO_UNDEFINED)
