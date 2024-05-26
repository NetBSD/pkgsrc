$NetBSD: patch-cmake_FindFFmpeg.cmake,v 1.1 2024/05/26 12:56:56 markd Exp $

Fix broken prefix

--- cmake/FindFFmpeg.cmake.orig	2016-02-06 13:44:51.000000000 +0000
+++ cmake/FindFFmpeg.cmake
@@ -89,16 +89,16 @@ macro(find_component _component _pkgconf
 
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
