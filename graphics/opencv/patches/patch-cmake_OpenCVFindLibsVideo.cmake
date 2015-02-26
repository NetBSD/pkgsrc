$NetBSD: patch-cmake_OpenCVFindLibsVideo.cmake,v 1.1 2015/02/26 17:52:12 tnn Exp $

OSX ffmpeg option build fixes from upstream 2.4 branch.

--- cmake/OpenCVFindLibsVideo.cmake.orig	2014-04-11 10:15:26.000000000 +0000
+++ cmake/OpenCVFindLibsVideo.cmake
@@ -177,42 +177,35 @@ if(WITH_FFMPEG)
         # Do an other trial
         FIND_FILE(BZIP2_LIBRARIES NAMES libbz2.so.1 PATHS /lib)
       endif()
-    endif(HAVE_FFMPEG)
-  endif()
-
-  if(APPLE)
-    find_path(FFMPEG_INCLUDE_DIR "libavformat/avformat.h"
-              PATHS /usr/local /usr /opt
-              PATH_SUFFIXES include
-              DOC "The path to FFMPEG headers")
-    if(FFMPEG_INCLUDE_DIR)
-      set(HAVE_GENTOO_FFMPEG TRUE)
-      set(FFMPEG_LIB_DIR "${FFMPEG_INCLUDE_DIR}/../lib" CACHE PATH "Full path of FFMPEG library directory")
-      if(EXISTS "${FFMPEG_LIB_DIR}/libavcodec.a")
-        set(HAVE_FFMPEG_CODEC 1)
-        set(ALIASOF_libavcodec_VERSION "Unknown")
-        if(EXISTS "${FFMPEG_LIB_DIR}/libavformat.a")
-          set(HAVE_FFMPEG_FORMAT 1)
+    else()
+      find_path(FFMPEG_INCLUDE_DIR "libavformat/avformat.h"
+                PATHS /usr/local /usr /opt
+                PATH_SUFFIXES include
+                DOC "The path to FFMPEG headers")
+      if(FFMPEG_INCLUDE_DIR)
+        set(HAVE_GENTOO_FFMPEG TRUE)
+        set(FFMPEG_LIB_DIR "${FFMPEG_INCLUDE_DIR}/../lib" CACHE PATH "Full path of FFMPEG library directory")
+        find_library(FFMPEG_CODEC_LIB "avcodec" HINTS "${FFMPEG_LIB_DIR}")
+        find_library(FFMPEG_FORMAT_LIB "avformat" HINTS "${FFMPEG_LIB_DIR}")
+        find_library(FFMPEG_UTIL_LIB "avutil" HINTS "${FFMPEG_LIB_DIR}")
+        find_library(FFMPEG_SWSCALE_LIB "swscale" HINTS "${FFMPEG_LIB_DIR}")
+        if(FFMPEG_CODEC_LIB AND FFMPEG_FORMAT_LIB AND
+           FFMPEG_UTIL_LIB AND FFMPEG_SWSCALE_LIB)
+          set(ALIASOF_libavcodec_VERSION "Unknown")
           set(ALIASOF_libavformat_VERSION "Unknown")
-          if(EXISTS "${FFMPEG_LIB_DIR}/libavutil.a")
-            set(HAVE_FFMPEG_UTIL 1)
-            set(ALIASOF_libavutil_VERSION "Unknown")
-            if(EXISTS "${FFMPEG_LIB_DIR}/libswscale.a")
-              set(HAVE_FFMPEG_SWSCALE 1)
-              set(ALIASOF_libswscale_VERSION "Unknown")
-              set(HAVE_FFMPEG 1)
-            endif()
-          endif()
+          set(ALIASOF_libavutil_VERSION "Unknown")
+          set(ALIASOF_libswscale_VERSION "Unknown")
+          set(HAVE_FFMPEG 1)
         endif()
-      endif()
-    endif(FFMPEG_INCLUDE_DIR)
-    if(HAVE_FFMPEG)
-      set(HIGHGUI_LIBRARIES ${HIGHGUI_LIBRARIES} "${FFMPEG_LIB_DIR}/libavcodec.a"
-          "${FFMPEG_LIB_DIR}/libavformat.a" "${FFMPEG_LIB_DIR}/libavutil.a"
-          "${FFMPEG_LIB_DIR}/libswscale.a")
-      ocv_include_directories(${FFMPEG_INCLUDE_DIR})
+      endif(FFMPEG_INCLUDE_DIR)
+      if(HAVE_FFMPEG)
+        set(HIGHGUI_LIBRARIES ${HIGHGUI_LIBRARIES}
+            ${FFMPEG_CODEC_LIB} ${FFMPEG_FORMAT_LIB}
+            ${FFMPEG_UTIL_LIB} ${FFMPEG_SWSCALE_LIB})
+        ocv_include_directories(${FFMPEG_INCLUDE_DIR})
+      endif(HAVE_FFMPEG)
     endif()
-  endif(APPLE)
+  endif()
 endif(WITH_FFMPEG)
 
 # --- VideoInput/DirectShow ---
