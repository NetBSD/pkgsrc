$NetBSD: patch-import_import_ffmpeg.c,v 1.3 2019/12/29 10:23:53 markd Exp $

Fixes building against FFmpeg version >= 4.0.0 (gentoo patch).

--- import/import_ffmpeg.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ import/import_ffmpeg.c
@@ -59,51 +59,51 @@ struct ffmpeg_codec {
 
 // fourCC to ID mapping taken from MPlayer's codecs.conf
 static struct ffmpeg_codec ffmpeg_codecs[] = {
-  {CODEC_ID_MSMPEG4V1, TC_CODEC_ERROR, "mp41",
+  {AV_CODEC_ID_MSMPEG4V1, TC_CODEC_ERROR, "mp41",
     {"MP41", "DIV1", ""}},
-  {CODEC_ID_MSMPEG4V2, TC_CODEC_MP42, "mp42",
+  {AV_CODEC_ID_MSMPEG4V2, TC_CODEC_MP42, "mp42",
     {"MP42", "DIV2", ""}},
-  {CODEC_ID_MSMPEG4V3, TC_CODEC_DIVX3, "msmpeg4",
+  {AV_CODEC_ID_MSMPEG4V3, TC_CODEC_DIVX3, "msmpeg4",
     {"DIV3", "DIV5", "AP41", "MPG3", "MP43", ""}},
-  {CODEC_ID_MPEG4, TC_CODEC_DIVX4, "mpeg4",
+  {AV_CODEC_ID_MPEG4, TC_CODEC_DIVX4, "mpeg4",
     {"DIVX", "XVID", "MP4S", "M4S2", "MP4V", "UMP4", "DX50", ""}},
-  {CODEC_ID_MJPEG, TC_CODEC_MJPEG, "mjpeg",
+  {AV_CODEC_ID_MJPEG, TC_CODEC_MJPEG, "mjpeg",
     {"MJPG", "AVRN", "AVDJ", "JPEG", "MJPA", "JFIF", ""}},
-  {CODEC_ID_MPEG1VIDEO, TC_CODEC_MPG1, "mpeg1video",
+  {AV_CODEC_ID_MPEG1VIDEO, TC_CODEC_MPG1, "mpeg1video",
     {"MPG1", ""}},
-  {CODEC_ID_DVVIDEO, TC_CODEC_DV, "dvvideo",
+  {AV_CODEC_ID_DVVIDEO, TC_CODEC_DV, "dvvideo",
     {"DVSD", ""}},
-  {CODEC_ID_WMV1, TC_CODEC_WMV1, "wmv1",
+  {AV_CODEC_ID_WMV1, TC_CODEC_WMV1, "wmv1",
     {"WMV1", ""}},
-  {CODEC_ID_WMV2, TC_CODEC_WMV2, "wmv2",
+  {AV_CODEC_ID_WMV2, TC_CODEC_WMV2, "wmv2",
     {"WMV2", ""}},
-  {CODEC_ID_HUFFYUV, TC_CODEC_HUFFYUV, "hfyu",
+  {AV_CODEC_ID_HUFFYUV, TC_CODEC_HUFFYUV, "hfyu",
     {"HFYU", ""}},
-  {CODEC_ID_H263I, TC_CODEC_H263I, "h263i",
+  {AV_CODEC_ID_H263I, TC_CODEC_H263I, "h263i",
     {"I263", ""}},
-  {CODEC_ID_H263P, TC_CODEC_H263P, "h263p",
+  {AV_CODEC_ID_H263P, TC_CODEC_H263P, "h263p",
     {"H263", "U263", "VIV1", ""}},
-  {CODEC_ID_H264, TC_CODEC_H264, "h264",
+  {AV_CODEC_ID_H264, TC_CODEC_H264, "h264",
     {"H264", "h264", "X264", "x264", "avc1", ""}},
-  {CODEC_ID_RV10, TC_CODEC_RV10, "rv10",
+  {AV_CODEC_ID_RV10, TC_CODEC_RV10, "rv10",
     {"RV10", "RV13", ""}},
-  {CODEC_ID_SVQ1, TC_CODEC_SVQ1, "svq1",
+  {AV_CODEC_ID_SVQ1, TC_CODEC_SVQ1, "svq1",
     {"SVQ1", ""}},
-  {CODEC_ID_SVQ3, TC_CODEC_SVQ3, "svq3",
+  {AV_CODEC_ID_SVQ3, TC_CODEC_SVQ3, "svq3",
     {"SVQ3", ""}},
-  {CODEC_ID_MPEG2VIDEO, TC_CODEC_MPEG2, "mpeg2video",
+  {AV_CODEC_ID_MPEG2VIDEO, TC_CODEC_MPEG2, "mpeg2video",
     {"MPG2", ""}},
-  {CODEC_ID_MPEG2VIDEO, TC_CODEC_MPEG, "mpeg2video",
+  {AV_CODEC_ID_MPEG2VIDEO, TC_CODEC_MPEG, "mpeg2video",
     {"MPG2", ""}},
-  {CODEC_ID_ASV1, TC_CODEC_ASV1, "asv1",
+  {AV_CODEC_ID_ASV1, TC_CODEC_ASV1, "asv1",
     {"ASV1", ""}},
-  {CODEC_ID_ASV2, TC_CODEC_ASV2, "asv2",
+  {AV_CODEC_ID_ASV2, TC_CODEC_ASV2, "asv2",
     {"ASV2", ""}},
-  {CODEC_ID_FFV1, TC_CODEC_FFV1, "ffv1",
+  {AV_CODEC_ID_FFV1, TC_CODEC_FFV1, "ffv1",
     {"FFV1", ""}},
-  {CODEC_ID_RAWVIDEO, TC_CODEC_YUV420P, "raw",
+  {AV_CODEC_ID_RAWVIDEO, TC_CODEC_YUV420P, "raw",
     {"I420", "IYUV", ""}},
-  {CODEC_ID_RAWVIDEO, TC_CODEC_YUV422P, "raw",
+  {AV_CODEC_ID_RAWVIDEO, TC_CODEC_YUV422P, "raw",
     {"Y42B", ""}},
   {0, TC_CODEC_UNKNOWN, NULL, {""}}};
 
@@ -302,7 +302,7 @@ do_avi:
 
     // Set these to the expected values so that ffmpeg's decoder can
     // properly detect interlaced input.
-    lavc_dec_context = avcodec_alloc_context();
+    lavc_dec_context = avcodec_alloc_context3(lavc_dec_codec);
     if (lavc_dec_context == NULL) {
       tc_log_error(MOD_NAME, "Could not allocate enough memory.");
       return TC_IMPORT_ERROR;
@@ -310,11 +310,11 @@ do_avi:
     lavc_dec_context->width  = x_dim;
     lavc_dec_context->height = y_dim;
 
-    if (vob->decolor) lavc_dec_context->flags |= CODEC_FLAG_GRAY;
+    if (vob->decolor) lavc_dec_context->flags |= AV_CODEC_FLAG_GRAY;
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)
     lavc_dec_context->error_resilience  = 2;
 #else
-    lavc_dec_context->error_recognition = 2;
+    lavc_dec_context->err_recognition = 2;
 #endif
     lavc_dec_context->error_concealment = 3;
     lavc_dec_context->workaround_bugs = FF_BUG_AUTODETECT;
@@ -324,13 +324,13 @@ do_avi:
     // XXX: some codecs need extra data
     switch (codec->id)
     {
-      case CODEC_ID_MJPEG: extra_data_size  = 28; break;
-      case CODEC_ID_LJPEG: extra_data_size  = 28; break;
-      case CODEC_ID_HUFFYUV: extra_data_size = 1000; break;
-      case CODEC_ID_ASV1: extra_data_size = 8; break;
-      case CODEC_ID_ASV2: extra_data_size = 8; break;
-      case CODEC_ID_WMV1: extra_data_size = 4; break;
-      case CODEC_ID_WMV2: extra_data_size = 4; break;
+      case AV_CODEC_ID_MJPEG: extra_data_size  = 28; break;
+      case AV_CODEC_ID_LJPEG: extra_data_size  = 28; break;
+      case AV_CODEC_ID_HUFFYUV: extra_data_size = 1000; break;
+      case AV_CODEC_ID_ASV1: extra_data_size = 8; break;
+      case AV_CODEC_ID_ASV2: extra_data_size = 8; break;
+      case AV_CODEC_ID_WMV1: extra_data_size = 4; break;
+      case AV_CODEC_ID_WMV2: extra_data_size = 4; break;
       default: extra_data_size = 0; break;
     }
 
@@ -344,7 +344,7 @@ do_avi:
     }
 
     TC_LOCK_LIBAVCODEC;
-    ret = avcodec_open(lavc_dec_context, lavc_dec_codec);
+    ret = avcodec_open2(lavc_dec_context, lavc_dec_codec, NULL);
     TC_UNLOCK_LIBAVCODEC;
     if (ret < 0) {
       tc_log_warn(MOD_NAME, "Could not initialize the '%s' codec.",
@@ -360,7 +360,7 @@ do_avi:
         frame_size = x_dim*y_dim + 2*UV_PLANE_SIZE(IMG_YUV_DEFAULT,x_dim,y_dim);
 
 	// we adapt the color space
-        if(codec->id == CODEC_ID_MJPEG) {
+        if(codec->id == AV_CODEC_ID_MJPEG) {
 	  enable_levels_filter();
         }
         break;
@@ -434,7 +434,7 @@ do_dv:
       }
 
       // we adapt the color space
-      if(codec->id == CODEC_ID_MJPEG) {
+      if(codec->id == AV_CODEC_ID_MJPEG) {
         enable_levels_filter();
       }
 
@@ -504,13 +504,13 @@ MOD_decode {
       int bkey = 0;
 
       // check for keyframes
-      if (codec->id == CODEC_ID_MSMPEG4V3) {
+      if (codec->id == AV_CODEC_ID_MSMPEG4V3) {
 	if (divx3_is_key(buffer)) bkey = 1;
       }
-      else if (codec->id == CODEC_ID_MPEG4) {
+      else if (codec->id == AV_CODEC_ID_MPEG4) {
 	if (mpeg4_is_key(buffer, bytes_read)) bkey = 1;
       }
-      else if (codec->id == CODEC_ID_MJPEG) {
+      else if (codec->id == AV_CODEC_ID_MJPEG) {
 	bkey = 1;
       }
 
@@ -580,8 +580,8 @@ retry:
 
     // Convert avcodec image to our internal YUV or RGB format
     switch (lavc_dec_context->pix_fmt) {
-      case PIX_FMT_YUVJ420P:
-      case PIX_FMT_YUV420P:
+      case AV_PIX_FMT_YUVJ420P:
+      case AV_PIX_FMT_YUV420P:
         src_fmt = IMG_YUV420P;
         YUV_INIT_PLANES(src_planes, frame, src_fmt,
                         lavc_dec_context->width, lavc_dec_context->height);
@@ -612,7 +612,7 @@ retry:
 	}
         break;
 
-      case PIX_FMT_YUV411P:
+      case AV_PIX_FMT_YUV411P:
         src_fmt = IMG_YUV411P;
         YUV_INIT_PLANES(src_planes, frame, src_fmt,
                         lavc_dec_context->width, lavc_dec_context->height);
@@ -640,8 +640,8 @@ retry:
         }
         break;
 
-      case PIX_FMT_YUVJ422P:
-      case PIX_FMT_YUV422P:
+      case AV_PIX_FMT_YUVJ422P:
+      case AV_PIX_FMT_YUV422P:
         src_fmt = IMG_YUV422P;
         YUV_INIT_PLANES(src_planes, frame, src_fmt,
                         lavc_dec_context->width, lavc_dec_context->height);
@@ -669,8 +669,8 @@ retry:
         }
 	break;
 
-      case PIX_FMT_YUVJ444P:
-      case PIX_FMT_YUV444P:
+      case AV_PIX_FMT_YUVJ444P:
+      case AV_PIX_FMT_YUV444P:
         src_fmt = IMG_YUV444P;
         YUV_INIT_PLANES(src_planes, frame, src_fmt,
                         lavc_dec_context->width, lavc_dec_context->height);
