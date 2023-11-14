$NetBSD: patch-src_decoder_plugins_FfmpegIo.cxx,v 1.3 2023/11/14 08:51:03 wiz Exp $

Fix build with ffmpeg 6.1.
https://github.com/MusicPlayerDaemon/MPD/issues/1898

--- src/decoder/plugins/FfmpegIo.cxx.orig	2023-10-08 08:11:05.000000000 +0000
+++ src/decoder/plugins/FfmpegIo.cxx
@@ -26,6 +26,7 @@
 
 extern "C" {
 #include <libavutil/mem.h>
+#include <libavutil/error.h>
 }
 
 AvioStream::~AvioStream()
