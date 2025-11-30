$NetBSD: patch-cmake_FindFFmpeg.cmake,v 1.1 2025/11/30 10:10:03 markd Exp $

Fix broken prefix

--- cmake/FindFFmpeg.cmake.orig	2025-11-05 15:41:13.000000000 +0000
+++ cmake/FindFFmpeg.cmake
@@ -115,16 +115,16 @@ macro(find_component _component _pkgconf
 
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
