$NetBSD: patch-cmake_admFFmpegPrepareTar.cmake,v 1.1 2011/02/17 09:20:17 markd Exp $

Dont assume tar will automatically uncompress

--- cmake/admFFmpegPrepareTar.cmake.orig	2011-02-08 11:17:55.000000000 +0000
+++ cmake/admFFmpegPrepareTar.cmake
@@ -9,7 +9,7 @@ if (EXISTS "${LIBRARY_SOURCE_DIR}/${FFMP
 	if (NOT EXISTS "${FFMPEG_SOURCE_DIR}/ffmpeg.c" OR NOT ${LAST_FFMPEG_VERSION} EQUAL ${FFMPEG_VERSION})
 		find_package(Tar)
 
-		execute_process(COMMAND ${TAR_EXECUTABLE} xvf ${FFMPEG_SOURCE_ARCHIVE}
+		execute_process(COMMAND ${TAR_EXECUTABLE} zxvf ${FFMPEG_SOURCE_ARCHIVE}
 					WORKING_DIRECTORY "${LIBRARY_SOURCE_DIR}"
 					${ffmpegExtractOutput})
 
@@ -20,7 +20,7 @@ if (EXISTS "${LIBRARY_SOURCE_DIR}/${FFMP
 	if (NOT EXISTS "${FFMPEG_SOURCE_DIR}/libswscale/swscale.c" OR NOT ${LAST_SWSCALE_VERSION} EQUAL ${SWSCALE_VERSION})
 		find_package(Tar)
 
-		execute_process(COMMAND ${TAR_EXECUTABLE} xvf ../${SWSCALE_SOURCE_ARCHIVE}
+		execute_process(COMMAND ${TAR_EXECUTABLE} zxvf ../${SWSCALE_SOURCE_ARCHIVE}
 					WORKING_DIRECTORY "${FFMPEG_SOURCE_DIR}"
 					${ffmpegExtractOutput})
 
@@ -31,4 +31,4 @@ if (EXISTS "${LIBRARY_SOURCE_DIR}/${FFMP
 	set(FFMPEG_PREPARED 1)
 	set(LAST_FFMPEG_VERSION "${FFMPEG_VERSION}" CACHE STRING "" FORCE)
 	set(LAST_SWSCALE_VERSION "${SWSCALE_VERSION}" CACHE STRING "" FORCE)
-endif (EXISTS "${LIBRARY_SOURCE_DIR}/${FFMPEG_SOURCE_ARCHIVE}" AND EXISTS "${LIBRARY_SOURCE_DIR}/${SWSCALE_SOURCE_ARCHIVE}")
\ No newline at end of file
+endif (EXISTS "${LIBRARY_SOURCE_DIR}/${FFMPEG_SOURCE_ARCHIVE}" AND EXISTS "${LIBRARY_SOURCE_DIR}/${SWSCALE_SOURCE_ARCHIVE}")
