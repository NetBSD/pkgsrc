$NetBSD: patch-cmake_modules_FindFFmpeg.cmake,v 1.1 2021/04/05 12:54:28 markd Exp $

Use correct variable to detect ffmpeg paths

--- cmake/modules/FindFFmpeg.cmake.orig	2021-02-24 23:19:59.000000000 +0000
+++ cmake/modules/FindFFmpeg.cmake
@@ -68,16 +68,16 @@ macro(find_component _component _pkgconf
 
   find_path(${_component}_INCLUDE_DIRS ${_header}
     HINTS
-      ${PC_LIB${_component}_INCLUDEDIR}
-      ${PC_LIB${_component}_INCLUDE_DIRS}
+      ${PC_${_component}_INCLUDEDIR}
+      ${PC_${_component}_INCLUDE_DIRS}
     PATH_SUFFIXES
       ffmpeg
   )
 
   find_library(${_component}_LIBRARIES NAMES ${_library}
       HINTS
-      ${PC_LIB${_component}_LIBDIR}
-      ${PC_LIB${_component}_LIBRARY_DIRS}
+      ${PC_${_component}_LIBDIR}
+      ${PC_${_component}_LIBRARY_DIRS}
   )
 
   set(${_component}_DEFINITIONS  ${PC_${_component}_CFLAGS_OTHER} CACHE STRING "The ${_component} CFLAGS.")
