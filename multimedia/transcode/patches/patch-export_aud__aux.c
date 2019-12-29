$NetBSD: patch-export_aud__aux.c,v 1.2 2019/12/29 10:23:53 markd Exp $

Fixes building against FFmpeg version >= 4.0.0 (gentoo patch).

--- export/aud_aux.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ export/aud_aux.c
@@ -326,10 +326,10 @@ static int tc_audio_init_ffmpeg(vob_t *v
 
     switch (o_codec) {
       case   0x50:
-        codeid = CODEC_ID_MP2;
+        codeid = AV_CODEC_ID_MP2;
         break;
       case 0x2000:
-        codeid = CODEC_ID_AC3;
+        codeid = AV_CODEC_ID_AC3;
         break;
       default:
         tc_warn("cannot init ffmpeg with %x", o_codec);
@@ -346,7 +346,7 @@ static int tc_audio_init_ffmpeg(vob_t *v
 
     //-- set parameters (bitrate, channels and sample-rate) --
     //--------------------------------------------------------
-    avcodec_get_context_defaults(&mpa_ctx);
+    avcodec_get_context_defaults3(&mpa_ctx, mpa_codec);
 #if LIBAVCODEC_VERSION_MAJOR < 53
     mpa_ctx.codec_type  = CODEC_TYPE_AUDIO;
 #else
@@ -359,11 +359,11 @@ static int tc_audio_init_ffmpeg(vob_t *v
     //-- open codec --
     //----------------
     TC_LOCK_LIBAVCODEC;
-    ret = avcodec_open(&mpa_ctx, mpa_codec);
+    ret = avcodec_open2(&mpa_ctx, mpa_codec, NULL);
     TC_UNLOCK_LIBAVCODEC;
     if (ret < 0) {
         tc_warn("tc_audio_init_ffmpeg: could not open %s codec !",
-                (codeid == CODEC_ID_MP2) ?"mpa" :"ac3");
+                (codeid == AV_CODEC_ID_MP2) ?"mpa" :"ac3");
         return(TC_EXPORT_ERROR);
     }
 
@@ -846,6 +846,9 @@ static int tc_audio_encode_ffmpeg(char *
 #ifdef HAVE_FFMPEG
     int  in_size, out_size;
     char *in_buf;
+    int got_packet;
+    AVPacket avpkt = { 0 };
+    AVFrame *frame = av_frame_alloc();
 
     //-- input buffer and amount of bytes --
     in_size = aud_size;
@@ -866,10 +869,14 @@ static int tc_audio_encode_ffmpeg(char *
 
     ac_memcpy(&mpa_buf[mpa_buf_ptr], in_buf, bytes_needed);
 
+    frame->nb_samples = mpa_ctx.frame_size;
+    avcodec_fill_audio_frame(frame, mpa_ctx.channels, mpa_ctx.sample_fmt, (const uint8_t *)mpa_buf, mpa_bytes_pf, 1);
+    avpkt.data = output;
+    avpkt.size = OUTPUT_SIZE;
     TC_LOCK_LIBAVCODEC;
-    out_size = avcodec_encode_audio(&mpa_ctx, (unsigned char *)output,
-                    OUTPUT_SIZE, (short *)mpa_buf);
+    out_size = avcodec_encode_audio2(&mpa_ctx, &avpkt, frame, &got_packet);
     TC_UNLOCK_LIBAVCODEC;
+    out_size = avpkt.size;
     tc_audio_write(output, out_size, avifile);
 
         in_size -= bytes_needed;
@@ -884,6 +891,7 @@ static int tc_audio_encode_ffmpeg(char *
 
     ac_memcpy(&mpa_buf[mpa_buf_ptr], aud_buffer, bytes_avail);
         mpa_buf_ptr += bytes_avail;
+        av_frame_free(&frame);
         return (0);
       }
     } //bytes availabe from last call?
@@ -893,10 +901,15 @@ static int tc_audio_encode_ffmpeg(char *
     //----------------------------------------------------
 
     while (in_size >= mpa_bytes_pf) {
+      av_frame_unref(frame);
+      frame->nb_samples = mpa_ctx.frame_size;
+      avcodec_fill_audio_frame(frame, mpa_ctx.channels, mpa_ctx.sample_fmt, (const uint8_t *)in_buf, mpa_bytes_pf, 1);
+      avpkt.data = output;
+      avpkt.size = OUTPUT_SIZE;
       TC_LOCK_LIBAVCODEC;
-      out_size = avcodec_encode_audio(&mpa_ctx, (unsigned char *)output,
-                      OUTPUT_SIZE, (short *)in_buf);
+      out_size = avcodec_encode_audio2(&mpa_ctx, &avpkt, frame, &got_packet);
       TC_UNLOCK_LIBAVCODEC;
+      out_size = avpkt.size;
 
       tc_audio_write(output, out_size, avifile);
 
@@ -904,6 +917,8 @@ static int tc_audio_encode_ffmpeg(char *
       in_buf  += mpa_bytes_pf;
     }
 
+    av_frame_free(&frame);
+
     //-- hold rest of bytes in mpa-buffer --
     //--------------------------------------
     if (in_size > 0) {
