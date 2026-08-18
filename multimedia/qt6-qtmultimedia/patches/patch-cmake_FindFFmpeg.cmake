$NetBSD: patch-cmake_FindFFmpeg.cmake,v 1.8 2026/08/18 18:26:04 adam Exp $

--exclude-libs is not available on Solaris/Illumos, according to the git commit
messages for this file about exlude-libs it was added relocation problems on
Linux so only use it on Linux.

--- cmake/FindFFmpeg.cmake.orig	2026-07-03 07:13:40.000000000 +0000
+++ cmake/FindFFmpeg.cmake
@@ -344,7 +344,7 @@ foreach (_component ${FFmpeg_FIND_COMPON
             target_link_libraries(${_target} INTERFACE "${${_component}_LIBRARY}")
 
             __ffmpeg_internal_set_dependencies(${_component})
-            if (UNIX AND NOT APPLE)
+            if (LINUX)
                 target_link_options(${_target} INTERFACE  "-Wl,--exclude-libs=lib${_lowerComponent}")
             endif ()
         endif()
