$NetBSD: patch-cmake_FindFFmpeg.cmake,v 1.1 2014/08/14 19:18:51 wiz Exp $

Fix ffmpeg detection.

--- cmake/FindFFmpeg.cmake.orig	2014-01-02 19:34:11.000000000 +0000
+++ cmake/FindFFmpeg.cmake
@@ -62,7 +62,7 @@ macro(find_component _component _pkgconf
      # in the FIND_PATH() and FIND_LIBRARY() calls
      find_package(PkgConfig)
      if (PKG_CONFIG_FOUND)
-       pkg_check_modules(PC_${_component} ${_pkgconfig})
+       pkg_check_modules(PC_LIB${_component} ${_pkgconfig})
      endif ()
   endif (NOT WIN32)
 
