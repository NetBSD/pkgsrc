$NetBSD: patch-src_decoder_FfmpegDecoderPlugin.cxx,v 1.1 2014/12/08 12:59:53 wiz Exp $

fix build with ffmpeg2-2.5
http://bugs.musicpd.org/view.php?id=4235

--- src/decoder/FfmpegDecoderPlugin.cxx.orig	2014-11-18 19:52:54.000000000 +0000
+++ src/decoder/FfmpegDecoderPlugin.cxx
@@ -397,7 +397,7 @@ ffmpeg_probe(Decoder *decoder, InputStre
 	/* this attribute was added in libav/ffmpeg version 11, but
 	   unfortunately it's "uint8_t" instead of "char", and it's
 	   not "const" - wtf? */
-	avpd.mime_type = (uint8_t *)const_cast<char *>(is.GetMimeType());
+	avpd.mime_type = const_cast<char *>(is.GetMimeType());
 #endif
 
 	return av_probe_input_format(&avpd, true);
