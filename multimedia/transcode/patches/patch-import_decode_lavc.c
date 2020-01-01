$NetBSD: patch-import_decode_lavc.c,v 1.3 2020/01/01 22:17:29 markd Exp $

Fixes building against FFmpeg version >= 3.0.0 (gentoo patch).

--- import/decode_lavc.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ import/decode_lavc.c
@@ -58,37 +58,37 @@ struct ffmpeg_codec {
 
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
-  {CODEC_ID_MPEG1VIDEO, TC_CODEC_MPEG1VIDEO, "mpeg1video",
+  {AV_CODEC_ID_MPEG1VIDEO, TC_CODEC_MPEG1VIDEO, "mpeg1video",
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
   {0, TC_CODEC_UNKNOWN, NULL, {""}}};
 
@@ -170,7 +170,7 @@ void decode_lavc(decode_t *decode)
 
   // Set these to the expected values so that ffmpeg's decoder can
   // properly detect interlaced input.
-  lavc_dec_context = avcodec_alloc_context();
+  lavc_dec_context = avcodec_alloc_context3(NULL);
   if (lavc_dec_context == NULL) {
       tc_log_error(__FILE__, "Could not allocate enough memory.");
       goto decoder_error;
@@ -181,12 +181,12 @@ void decode_lavc(decode_t *decode)
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)
   lavc_dec_context->error_resilience  = 2;
 #else
-  lavc_dec_context->error_recognition = 2;
+  lavc_dec_context->err_recognition = 2;
 #endif
   lavc_dec_context->error_concealment = 3;
   lavc_dec_context->workaround_bugs = FF_BUG_AUTODETECT;
 
-  if (avcodec_open(lavc_dec_context, lavc_dec_codec) < 0) {
+  if (avcodec_open2(lavc_dec_context, lavc_dec_codec, NULL) < 0) {
       tc_log_error(__FILE__, "Could not initialize the '%s' codec.",
 		   codec->name);
       goto decoder_error;
@@ -290,8 +290,8 @@ void decode_lavc(decode_t *decode)
 
       // Convert avcodec image to the requested YUV or RGB format
       switch (lavc_dec_context->pix_fmt) {
-	case PIX_FMT_YUVJ420P:
-	case PIX_FMT_YUV420P:
+	case AV_PIX_FMT_YUVJ420P:
+	case AV_PIX_FMT_YUV420P:
 	    // Remove "dead space" at right edge of planes, if any
 	    if (picture.linesize[0] != lavc_dec_context->width) {
 		int y;
@@ -315,7 +315,7 @@ void decode_lavc(decode_t *decode)
 			  pix_fmt==TC_CODEC_YUV420P ? IMG_YUV420P : IMG_RGB_DEFAULT,
 			  lavc_dec_context->width, lavc_dec_context->height);
 	    break;
-	case PIX_FMT_YUV411P:
+	case AV_PIX_FMT_YUV411P:
 	    if (picture.linesize[0] != lavc_dec_context->width) {
 		int y;
 		for (y = 0; y < lavc_dec_context->height; y++) {
@@ -334,8 +334,8 @@ void decode_lavc(decode_t *decode)
 			  pix_fmt==TC_CODEC_YUV420P ? IMG_YUV420P : IMG_RGB_DEFAULT,
 			  lavc_dec_context->width, lavc_dec_context->height);
 	    break;
-	case PIX_FMT_YUVJ422P:
-	case PIX_FMT_YUV422P:
+	case AV_PIX_FMT_YUVJ422P:
+	case AV_PIX_FMT_YUV422P:
 	    if (picture.linesize[0] != lavc_dec_context->width) {
 		int y;
 		for (y = 0; y < lavc_dec_context->height; y++) {
@@ -354,8 +354,8 @@ void decode_lavc(decode_t *decode)
 			  pix_fmt==TC_CODEC_YUV420P ? IMG_YUV420P : IMG_RGB_DEFAULT,
 			  lavc_dec_context->width, lavc_dec_context->height);
 	    break;
-	case PIX_FMT_YUVJ444P:
-	case PIX_FMT_YUV444P:
+	case AV_PIX_FMT_YUVJ444P:
+	case AV_PIX_FMT_YUV444P:
 	    if (picture.linesize[0] != lavc_dec_context->width) {
 		int y;
 		for (y = 0; y < lavc_dec_context->height; y++) {
