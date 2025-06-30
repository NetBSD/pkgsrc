$NetBSD: patch-cmake_FindFFmpeg.cmake,v 1.6 2025/06/30 15:18:51 adam Exp $

--exclude-libs is not available on Solaris/Illumos, according to the git commit
messages for this file about exlude-libs it was added relocation problems on
Linux so only use it on Linux.

--- cmake/FindFFmpeg.cmake.orig	2025-05-04 13:16:35.000000000 +0000
+++ cmake/FindFFmpeg.cmake
@@ -338,7 +338,7 @@ foreach (_component ${FFmpeg_FIND_COMPON
 
             __ffmpeg_internal_set_dependencies(${_component})
             target_link_libraries(FFmpeg::${_lowerComponent} INTERFACE "${${_component}_LIBRARY_NAME}")
-            if (UNIX AND NOT APPLE)
+            if (LINUX)
                 target_link_options(FFmpeg::${_lowerComponent} INTERFACE  "-Wl,--exclude-libs=lib${_lowerComponent}")
             endif ()
         endif()
