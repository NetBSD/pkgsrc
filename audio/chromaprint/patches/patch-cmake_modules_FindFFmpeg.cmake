$NetBSD: patch-cmake_modules_FindFFmpeg.cmake,v 1.2 2015/10/27 06:48:57 adam Exp $

Include ffmpeg2 pkgsrc paths in search path.

--- cmake/modules/FindFFmpeg.cmake.orig	2013-11-23 15:43:42.000000000 +0000
+++ cmake/modules/FindFFmpeg.cmake
@@ -28,6 +28,7 @@ MACRO(FFMPEG_FIND varname shortname head
 	FIND_PATH(FFMPEG_${varname}_INCLUDE_DIRS lib${shortname}/${headername}
 		PATHS
 		${FFMPEG_ROOT}/include
+		${FFMPEG_ROOT}/include/ffmpeg2
 		$ENV{FFMPEG_DIR}/include
 		~/Library/Frameworks
 		/Library/Frameworks
@@ -43,7 +44,7 @@ MACRO(FFMPEG_FIND varname shortname head
 		DOC "Location of FFMPEG Headers"
 	)
 	FIND_PATH(FFMPEG_${varname}_INCLUDE_DIRS lib${shortname}/${headername}
-		PATH_SUFFIXES ffmpeg
+		PATH_SUFFIXES ffmpeg ffmpeg2
 		DOC "Location of FFMPEG Headers"
 	)
 
@@ -51,6 +52,7 @@ MACRO(FFMPEG_FIND varname shortname head
         NAMES ${shortname}
         PATHS
         ${FFMPEG_ROOT}/lib
+        ${FFMPEG_ROOT}/lib/ffmpeg2
         $ENV{FFMPEG_DIR}/lib
         ~/Library/Frameworks
         /Library/Frameworks
