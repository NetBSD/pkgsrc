$NetBSD: patch-export_export_ffmpeg.c,v 1.2 2015/11/21 17:14:26 adam Exp $

Fixes building against FFmpeg version >= 2.0.0 (gentoo patch).

--- export/export_ffmpeg.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ export/export_ffmpeg.c
@@ -122,6 +122,7 @@ static uint8_t             *img_buffer =
 static AVFrame             *lavc_convert_frame = NULL;
 
 static AVCodec             *lavc_venc_codec = NULL;
+static AVDictionary        *lavc_venc_opts = NULL;
 static AVFrame             *lavc_venc_frame = NULL;
 static AVCodecContext      *lavc_venc_context;
 static avi_t               *avifile = NULL;
@@ -180,7 +181,7 @@ static char *tc_strchrnul(const char *s,
 
 
 /* START: COPIED FROM ffmpeg-0.5_p22846(ffmpeg.c, cmdutils.c) */
-#include <libavcodec/opt.h>
+#include <libavutil/opt.h>
 #include <libavutil/avstring.h>
 #include <libswscale/swscale.h>
 
@@ -470,7 +471,6 @@ MOD_init
     }
 
     TC_LOCK_LIBAVCODEC;
-    avcodec_init();
     avcodec_register_all();
     TC_UNLOCK_LIBAVCODEC;
 
@@ -486,7 +486,7 @@ MOD_init
 		            codec->name, codec->fourCC, codec->comments);
     }
 
-    lavc_venc_context = avcodec_alloc_context();
+    lavc_venc_context = avcodec_alloc_context3(lavc_venc_codec);
     lavc_venc_frame   = avcodec_alloc_frame();
 
     lavc_convert_frame= avcodec_alloc_frame();
@@ -634,7 +634,7 @@ MOD_init
         lavc_param_rc_max_rate = 2516;
         lavc_param_rc_buffer_size = 224 * 8;
         lavc_param_rc_buffer_aggressivity = 99;
-        lavc_param_scan_offset = CODEC_FLAG_SVCD_SCAN_OFFSET;
+        lavc_param_scan_offset = 1;
 
         break;
 
@@ -674,7 +674,7 @@ MOD_init
 
         lavc_param_rc_buffer_size = 224 * 8;
         lavc_param_rc_buffer_aggressivity = 99;
-        lavc_param_scan_offset = CODEC_FLAG_SVCD_SCAN_OFFSET;
+        lavc_param_scan_offset = 1;
 
         break;
 
@@ -838,8 +838,13 @@ MOD_init
     lavc_venc_context->rc_strategy        = lavc_param_vrc_strategy;
     lavc_venc_context->b_frame_strategy   = lavc_param_vb_strategy;
     lavc_venc_context->b_quant_offset     = lavc_param_vb_qoffset;
-    lavc_venc_context->luma_elim_threshold= lavc_param_luma_elim_threshold;
-    lavc_venc_context->chroma_elim_threshold= lavc_param_chroma_elim_threshold;
+
+    char buf[1024];
+#define set_dict_opt(val, opt) \
+	snprintf(buf, sizeof(buf), "%i", val); \
+	av_dict_set(&lavc_venc_opts, opt, buf, 0)
+    set_dict_opt(lavc_param_luma_elim_threshold, "luma_elim_threshold");
+    set_dict_opt(lavc_param_chroma_elim_threshold, "chroma_elim_threshold");
     lavc_venc_context->rtp_payload_size   = lavc_param_packet_size;
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)   
     if (lavc_param_packet_size)
@@ -870,7 +875,7 @@ MOD_init
     lavc_venc_context->context_model      = lavc_param_context;
     lavc_venc_context->scenechange_threshold= lavc_param_sc_threshold;
     lavc_venc_context->noise_reduction    = lavc_param_noise_reduction;
-    lavc_venc_context->inter_threshold    = lavc_param_inter_threshold;
+    set_dict_opt(lavc_param_inter_threshold, "inter_threshold");
     lavc_venc_context->intra_dc_precision = lavc_param_intra_dc_precision;
     lavc_venc_context->skip_top           = lavc_param_skip_top;
     lavc_venc_context->skip_bottom        = lavc_param_skip_bottom;
@@ -887,7 +892,7 @@ MOD_init
 		    lavc_venc_context->thread_count);
     }
 
-    avcodec_thread_init(lavc_venc_context, lavc_param_threads);
+    lavc_venc_context->thread_count = lavc_param_threads;
 
     if (lavc_param_intra_matrix) {
         char *tmp;
@@ -1065,15 +1070,12 @@ MOD_init
     lavc_venc_context->flags |= lavc_param_closedgop;
     lavc_venc_context->flags |= lavc_param_trunc;
     lavc_venc_context->flags |= lavc_param_aic;
-    lavc_venc_context->flags |= lavc_param_umv;
     lavc_venc_context->flags |= lavc_param_v4mv;
-    lavc_venc_context->flags |= lavc_param_data_partitioning;
-    lavc_venc_context->flags |= lavc_param_cbp;
+    if(lavc_param_cbp)
+    	av_dict_set(&lavc_venc_opts, "mpv_flags", "+cbp_rd", 0);
     lavc_venc_context->flags |= lavc_param_mv0;
-    lavc_venc_context->flags |= lavc_param_qp_rd;
-    lavc_venc_context->flags |= lavc_param_scan_offset;
-    lavc_venc_context->flags |= lavc_param_ss;
-    lavc_venc_context->flags |= lavc_param_alt;
+    if(lavc_param_qp_rd)
+    	av_dict_set(&lavc_venc_opts, "mpv_flags", "+qp_rd", 0);
     lavc_venc_context->flags |= lavc_param_ilme;
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)   
     lavc_venc_context->flags |= lavc_param_trell;
@@ -1203,9 +1205,8 @@ MOD_init
 
     lavc_venc_context->me_method = ME_ZERO + lavc_param_vme;
 
-
 	/* FIXME: transcode itself contains "broken ffmpeg default settings", thus we need to override them! */
-	if (lavc_param_video_preset) {
+	if (lavc_param_video_preset && strcmp(lavc_param_video_preset, "none")) {
 		avcodec_opts[AVMEDIA_TYPE_VIDEO] = lavc_venc_context;
 		video_codec_name = ffmpeg_codec_name(codec->name);
 
@@ -1241,20 +1242,39 @@ MOD_init
 		}
 	}
 
+    if (lavc_param_scan_offset) {
+      av_dict_set(&lavc_venc_opts, "scan_offset", "1", 0);
+    }
+
+    if (lavc_param_ss) {
+      av_dict_set(&lavc_venc_opts, "structured_slices", "1", 0);
+    }
+
+    if (lavc_param_alt) {
+      av_dict_set(&lavc_venc_opts, "alternate_scan", "1", 0);
+    }
+
+    if (lavc_param_umv) {
+      av_dict_set(&lavc_venc_opts, "umv", "1", 0);
+    }
+
+    if (lavc_param_data_partitioning) {
+      av_dict_set(&lavc_venc_opts, "vdpart", "1", 0);
+    }
 
     //-- open codec --
     //----------------
     TC_LOCK_LIBAVCODEC;
-    ret = avcodec_open(lavc_venc_context, lavc_venc_codec);
+    ret = avcodec_open2(lavc_venc_context, lavc_venc_codec, &lavc_venc_opts);
     TC_UNLOCK_LIBAVCODEC;
     if (ret < 0) {
       tc_log_warn(MOD_NAME, "could not open FFMPEG codec");
       return TC_EXPORT_ERROR;
     }
 
-    if (lavc_venc_context->codec->encode == NULL) {
+    if (av_codec_is_encoder(lavc_venc_context->codec) == 0) {
       tc_log_warn(MOD_NAME, "could not open FFMPEG codec "
-              "(lavc_venc_context->codec->encode == NULL)");
+              "(av_codec_is_encoder(lavc_venc_context->codec) == 0)");
       return TC_EXPORT_ERROR;
     }
 
