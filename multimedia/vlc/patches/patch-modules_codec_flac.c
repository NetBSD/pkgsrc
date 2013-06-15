$NetBSD: patch-modules_codec_flac.c,v 1.1 2013/06/15 22:59:10 wiz Exp $

--- modules/codec/flac.c.orig	2011-07-12 18:11:24.000000000 +0000
+++ modules/codec/flac.c
@@ -38,8 +38,8 @@
 #include <vlc_codec.h>
 #include <vlc_aout.h>
 
-#include <stream_decoder.h>
-#include <stream_encoder.h>
+#include <FLAC/stream_decoder.h>
+#include <FLAC/stream_encoder.h>
 
 #include <vlc_block_helper.h>
 #include <vlc_bits.h>
