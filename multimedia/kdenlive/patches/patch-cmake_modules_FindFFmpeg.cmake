$NetBSD: patch-cmake_modules_FindFFmpeg.cmake,v 1.1 2026/09/06 11:03:04 markd Exp $

Fix broken prefix

--- cmake/modules/FindFFmpeg.cmake.orig	2026-08-14 03:27:38.000000000 +0000
+++ cmake/modules/FindFFmpeg.cmake
@@ -139,16 +139,16 @@ macro(find_component _component _pkgconf
 
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
