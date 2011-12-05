$NetBSD: patch-plugins_video_MPEG4-ffmpeg_mpeg4.cxx,v 1.1.2.2 2011/12/05 20:08:05 tron Exp $

--- plugins/video/MPEG4-ffmpeg/mpeg4.cxx.orig	2009-09-22 00:57:53.000000000 +0000
+++ plugins/video/MPEG4-ffmpeg/mpeg4.cxx
@@ -828,11 +828,11 @@ int MPEG4EncoderContext::EncodeFrames(co
         // Should the next frame be an I-Frame?
         if ((flags & PluginCodec_CoderForceIFrame) || (_frameNum == 0))
         {
-            _avpicture->pict_type = FF_I_TYPE;
+            _avpicture->pict_type = AV_PICTURE_TYPE_I;
         }
         else // No IFrame requested, let avcodec decide what to do
         {
-            _avpicture->pict_type = 0;
+            _avpicture->pict_type = AV_PICTURE_TYPE_NONE;
         }
 
         // Encode a frame
@@ -1363,7 +1363,7 @@ bool MPEG4DecoderContext::DecoderError(i
     if (_doError) {
         int errors = 0;
         MpegEncContext *s = (MpegEncContext *) _avcontext->priv_data;
-        if (s->error_count && _avcontext->coded_frame->pict_type == FF_I_TYPE) {
+        if (s->error_count && _avcontext->coded_frame->pict_type == AV_PICTURE_TYPE_I) {
             const uint8_t badflags = AC_ERROR | DC_ERROR | MV_ERROR;
             for (int i = 0; i < s->mb_num && errors < threshold; ++i) {
                 if (s->error_status_table[s->mb_index2xy[i]] & badflags)
