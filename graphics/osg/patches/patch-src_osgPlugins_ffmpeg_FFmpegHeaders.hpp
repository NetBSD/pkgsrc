$NetBSD: patch-src_osgPlugins_ffmpeg_FFmpegHeaders.hpp,v 1.2 2012/03/07 16:27:35 adam Exp $

Point to correct header files.

--- src/osgPlugins/ffmpeg/FFmpegHeaders.hpp.orig	2012-03-05 21:20:14.000000000 +0000
+++ src/osgPlugins/ffmpeg/FFmpegHeaders.hpp
@@ -9,9 +9,9 @@ extern "C"
 #define FF_API_OLD_SAMPLE_FMT 0
 #include <errno.h>    // for error codes defined in avformat.h
 #include <stdint.h>
-#include <avcodec.h>
-#include <avformat.h>
-#include <avdevice.h>
+#include <libavcodec/avcodec.h>
+#include <libavformat/avformat.h>
+#include <libavdevice/avdevice.h>
 
 #ifdef USE_SWSCALE    
     #include <swscale.h>
