$NetBSD: patch-modules_codec_flac.c,v 1.1 2013/06/15 23:05:36 wiz Exp $

--- modules/codec/flac.c.orig	2013-01-25 12:30:14.000000000 +0000
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
