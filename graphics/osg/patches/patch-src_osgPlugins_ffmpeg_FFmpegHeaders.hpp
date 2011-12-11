$NetBSD: patch-src_osgPlugins_ffmpeg_FFmpegHeaders.hpp,v 1.1 2011/12/11 11:59:06 marino Exp $

--- src/osgPlugins/ffmpeg/FFmpegHeaders.hpp.orig	2010-03-19 08:03:02.000000000 +0000
+++ src/osgPlugins/ffmpeg/FFmpegHeaders.hpp
@@ -6,11 +6,12 @@
 extern "C"
 {
 #define __STDC_CONSTANT_MACROS
+#define FF_API_OLD_SAMPLE_FMT 0
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
