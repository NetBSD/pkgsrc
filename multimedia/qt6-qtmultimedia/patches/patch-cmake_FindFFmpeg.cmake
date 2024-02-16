$NetBSD: patch-cmake_FindFFmpeg.cmake,v 1.2 2024/02/16 17:39:05 adam Exp $

* --exclude-libs is not available on Solaris/Illumos, according to
  the git commit messages for this file about exlude-libs it was
  added relocation problems on Linux so only use it on Linux

--- cmake/FindFFmpeg.cmake.orig	2024-02-10 00:08:32.000000000 +0000
+++ cmake/FindFFmpeg.cmake
@@ -288,7 +288,7 @@ endfunction()
           __ffmpeg_internal_set_dependencies(${_lowerComponent})
         endif()
         target_link_libraries(FFmpeg::${_lowerComponent} INTERFACE "${${_component}_LIBRARY_NAME}")
-        if (UNIX AND NOT APPLE)
+        if (LINUX)
           target_link_options(FFmpeg::${_lowerComponent} INTERFACE  "-Wl,--exclude-libs=lib${_lowerComponent}")
         endif ()
       endif()
