$NetBSD: patch-cmake_modules_FindFreetype.cmake,v 1.1 2014/03/23 15:16:35 spz Exp $

make it deal gracefully with both freetype 2.4.* and 2.5.*

--- cmake/modules/FindFreetype.cmake.orig	2013-09-10 12:25:47.000000000 +0000
+++ cmake/modules/FindFreetype.cmake
@@ -12,7 +12,7 @@ libfind_pkg_check_modules(Freetype_PKGCO
 
 # Include dir
 find_path(Freetype_INCLUDE_DIR
-  NAMES freetype/freetype.h
+  NAMES ft2build.h
   PATHS ${Freetype_PKGCONF_INCLUDE_DIRS}
   PATH_SUFFIXES freetype2
 )
