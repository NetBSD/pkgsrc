$NetBSD: patch-cmake_FindFFmpeg.cmake,v 1.7 2025/09/22 05:43:26 adam Exp $

--exclude-libs is not available on Solaris/Illumos, according to the git commit
messages for this file about exlude-libs it was added relocation problems on
Linux so only use it on Linux.

--- cmake/FindFFmpeg.cmake.orig	2025-08-18 00:47:41.000000000 +0000
+++ cmake/FindFFmpeg.cmake
@@ -333,7 +333,7 @@ foreach (_component ${FFmpeg_FIND_COMPON
             target_link_directories(${_target} INTERFACE ${${_component}_LIBRARY_DIR})
 
             __ffmpeg_internal_set_dependencies(${_component})
-            if (UNIX AND NOT APPLE)
+            if (LINUX)
                 target_link_options(${_target} INTERFACE  "-Wl,--exclude-libs=lib${_lowerComponent}")
             endif ()
         endif()
