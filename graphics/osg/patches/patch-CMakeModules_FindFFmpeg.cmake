$NetBSD: patch-CMakeModules_FindFFmpeg.cmake,v 1.1 2018/08/04 01:05:10 nia Exp $

Find ffmpeg from pkgsrc

--- CMakeModules/FindFFmpeg.cmake.orig	2017-08-28 16:50:49.000000000 +0000
+++ CMakeModules/FindFFmpeg.cmake
@@ -30,7 +30,7 @@ MACRO(FFMPEG_FIND varname shortname head
 
     FIND_PATH(FFMPEG_${varname}_INCLUDE_DIRS lib${shortname}/${headername}
         PATHS
-        ${FFMPEG_ROOT}/include
+        ${FFMPEG_ROOT}/include/ffmpeg4
         $ENV{FFMPEG_DIR}/include
         ${FFMPEG_ROOT}
         $ENV{FFMPEG_DIR}
@@ -43,7 +43,7 @@ MACRO(FFMPEG_FIND varname shortname head
         /opt/csw/include # Blastwave
         /opt/include
         /usr/freeware/include
-        PATH_SUFFIXES ffmpeg
+        PATH_SUFFIXES ffmpeg4
         DOC "Location of FFMPEG Headers"
     )
 
@@ -69,9 +69,9 @@ MACRO(FFMPEG_FIND varname shortname head
     FIND_LIBRARY(FFMPEG_${varname}_LIBRARIES
         NAMES ${shortname}
         PATHS
-        ${FFMPEG_ROOT}/lib
+        ${FFMPEG_ROOT}/lib/ffmpeg4
         $ENV{FFMPEG_DIR}/lib
-        ${FFMPEG_ROOT}/lib${shortname}
+        ${FFMPEG_ROOT}/lib/ffmpeg4${shortname}
         $ENV{FFMPEG_DIR}/lib${shortname}
         ~/Library/Frameworks
         /Library/Frameworks
@@ -84,6 +84,7 @@ MACRO(FFMPEG_FIND varname shortname head
         /opt/csw/lib
         /opt/lib
         /usr/freeware/lib64
+        PATH_SUFFIXES ffmpeg4
         DOC "Location of FFMPEG Libraries"
     )
 
