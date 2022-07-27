$NetBSD: patch-src_decoder_plugins_FfmpegIo.cxx,v 1.1 2022/07/27 09:42:45 wiz Exp $

Fix build with ffmpeg 5.1.
https://github.com/MusicPlayerDaemon/MPD/commit/59792cb0b801854ee41be72d33db9542735df754

--- src/decoder/plugins/FfmpegIo.cxx.orig	2022-07-08 23:05:38.000000000 +0000
+++ src/decoder/plugins/FfmpegIo.cxx
@@ -21,10 +21,13 @@
 #define __STDC_CONSTANT_MACROS
 
 #include "FfmpegIo.hxx"
-#include "libavutil/mem.h"
 #include "../DecoderAPI.hxx"
 #include "input/InputStream.hxx"
 
+extern "C" {
+#include "libavutil/mem.h"
+}
+
 AvioStream::~AvioStream()
 {
 	if (io != nullptr) {
