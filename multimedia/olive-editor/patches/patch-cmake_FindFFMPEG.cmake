$NetBSD: patch-cmake_FindFFMPEG.cmake,v 1.1 2019/09/19 14:28:15 nia Exp $

Support pkgsrc's install locations for ffmpeg.

--- cmake/FindFFMPEG.cmake.orig	2019-07-09 15:16:17.000000000 +0000
+++ cmake/FindFFMPEG.cmake
@@ -34,6 +34,7 @@ function (_ffmpeg_find component headern
     NAMES
       "lib${component}/${headername}"
     PATHS
+      "${FFMPEG_INCLUDE_ROOT}"
       "${FFMPEG_ROOT}/include"
       ~/Library/Frameworks
       /Library/Frameworks
@@ -59,6 +60,7 @@ function (_ffmpeg_find component headern
     NAMES
       "${component}"
     PATHS
+      "${FFMPEG_LIB_ROOT}"
       "${FFMPEG_ROOT}/lib"
       ~/Library/Frameworks
       /Library/Frameworks
