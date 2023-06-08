$NetBSD: patch-src_audio_ffmpeg__audio__processor.h,v 1.1 2023/06/08 07:05:18 wiz Exp $

Support ffmpeg5
https://github.com/acoustid/chromaprint/pull/120/files

--- src/audio/ffmpeg_audio_processor.h.orig	2021-12-23 05:57:54.000000000 +0000
+++ src/audio/ffmpeg_audio_processor.h
@@ -10,8 +10,6 @@
 
 #if defined(USE_SWRESAMPLE)
 #include "audio/ffmpeg_audio_processor_swresample.h"
-#elif defined(USE_AVRESAMPLE)
-#include "audio/ffmpeg_audio_processor_avresample.h"
 #else
 #error "no audio processing library"
 #endif
