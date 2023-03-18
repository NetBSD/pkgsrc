$NetBSD: patch-cmake_FindFFmpeg.cmake,v 1.1 2023/03/18 13:14:16 nros Exp $

* --exclude-libs is not available on Solaris/Illumos, according to
  the git commit messages for this file about exlude-libs it was
  added relocation problems on Linux so only use it on Linux

--- cmake/FindFFmpeg.cmake.orig	2023-03-18 11:53:01.741033419 +0000
+++ cmake/FindFFmpeg.cmake
@@ -247,7 +247,7 @@ endfunction()
             __ffmpeg_internal_set_dependencies(${_lowerComponent})
         endif()
         target_link_libraries(FFmpeg::${_lowerComponent} INTERFACE "${${_component}_LIBRARY}")
-        if (UNIX AND NOT APPLE)
+        if (LINUX)
           target_link_options(FFmpeg::${_lowerComponent} INTERFACE  "-Wl,--exclude-libs=lib${_lowerComponent}")
         endif ()
     endif()
