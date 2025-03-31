$NetBSD: patch-cmake_FindFFmpeg.cmake,v 1.5 2025/03/31 16:38:07 adam Exp $

Use correct path to pkgconfig files.

--exclude-libs is not available on Solaris/Illumos, according to the git commit
messages for this file about exlude-libs it was added relocation problems on
Linux so only use it on Linux.

--- cmake/FindFFmpeg.cmake.orig	2025-03-31 15:44:25.733843536 +0000
+++ cmake/FindFFmpeg.cmake
@@ -255,7 +255,7 @@ function(__ffmpeg_internal_set_dependenc
 
     # The pkgconfig directory is always in lib/pkgconfig/, even on Windows
     # where libs and dlls are in bin/
-    set(PC_FILE ${${_component}_LIBRARY_DIR}/../lib/pkgconfig/lib${lib}.pc)
+    set(PC_FILE ${${_component}_LIBRARY_DIR}/pkgconfig/lib${lib}.pc)
 
     if(EXISTS ${PC_FILE})
         file(READ ${PC_FILE} pcfile)
@@ -314,7 +314,7 @@ foreach (_component ${FFmpeg_FIND_COMPON
 
             __ffmpeg_internal_set_dependencies(${_component})
             target_link_libraries(FFmpeg::${_lowerComponent} INTERFACE "${${_component}_LIBRARY_NAME}")
-            if (UNIX AND NOT APPLE)
+            if (LINUX)
                 target_link_options(FFmpeg::${_lowerComponent} INTERFACE  "-Wl,--exclude-libs=lib${_lowerComponent}")
             endif ()
         endif()
