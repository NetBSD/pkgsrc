$NetBSD: patch-export_export_ffmpeg.c,v 1.3 2019/12/29 10:23:53 markd Exp $

Fixes building against FFmpeg version >= 4.0.0 (gentoo patch).

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
 
@@ -249,9 +250,9 @@ int opt_default(const char *opt, const c
     for(type=0; type<AVMEDIA_TYPE_NB && ret>= 0; type++){
 		/* GLUE: +if */
 		if (type == AVMEDIA_TYPE_VIDEO) {
-        const AVOption *o2 = av_find_opt(avcodec_opts[0], opt, NULL, opt_types[type], opt_types[type]);
-        if(o2)
-            ret = av_set_string3(avcodec_opts[type], opt, arg, 1, &o);
+        o = av_opt_find(avcodec_opts[0], opt, NULL, opt_types[type], opt_types[type]);
+        if(o)
+            ret = av_opt_set(avcodec_opts[type], opt, arg, 0);
 		/* GLUE: +if */
 		}
     }
@@ -266,7 +267,10 @@ int opt_default(const char *opt, const c
         if(opt[0] == 'a')
             ret = av_set_string3(avcodec_opts[AVMEDIA_TYPE_AUDIO], opt+1, arg, 1, &o);
         else */ if(opt[0] == 'v')
-            ret = av_set_string3(avcodec_opts[AVMEDIA_TYPE_VIDEO], opt+1, arg, 1, &o);
+	{
+	    o = av_opt_find(avcodec_opts[AVMEDIA_TYPE_VIDEO], opt+1, NULL, 0, 0);
+            ret = av_opt_set(avcodec_opts[AVMEDIA_TYPE_VIDEO], opt+1, arg, 0);
+	}
 		/* GLUE: disabling
         else if(opt[0] == 's')
             ret = av_set_string3(avcodec_opts[AVMEDIA_TYPE_SUBTITLE], opt+1, arg, 1, &o);
@@ -470,7 +474,6 @@ MOD_init
     }
 
     TC_LOCK_LIBAVCODEC;
-    avcodec_init();
     avcodec_register_all();
     TC_UNLOCK_LIBAVCODEC;
 
@@ -486,11 +489,11 @@ MOD_init
 		            codec->name, codec->fourCC, codec->comments);
     }
 
-    lavc_venc_context = avcodec_alloc_context();
-    lavc_venc_frame   = avcodec_alloc_frame();
+    lavc_venc_context = avcodec_alloc_context3(lavc_venc_codec);
+    lavc_venc_frame   = av_frame_alloc();
 
-    lavc_convert_frame= avcodec_alloc_frame();
-    size = avpicture_get_size(PIX_FMT_RGB24, vob->ex_v_width, vob->ex_v_height);
+    lavc_convert_frame= av_frame_alloc();
+    size = avpicture_get_size(AV_PIX_FMT_RGB24, vob->ex_v_width, vob->ex_v_height);
     enc_buffer = tc_malloc(size);
 
     if (lavc_venc_context == NULL || !enc_buffer || !lavc_convert_frame) {
@@ -634,7 +637,7 @@ MOD_init
         lavc_param_rc_max_rate = 2516;
         lavc_param_rc_buffer_size = 224 * 8;
         lavc_param_rc_buffer_aggressivity = 99;
-        lavc_param_scan_offset = CODEC_FLAG_SVCD_SCAN_OFFSET;
+        lavc_param_scan_offset = 1;
 
         break;
 
@@ -674,7 +677,7 @@ MOD_init
 
         lavc_param_rc_buffer_size = 224 * 8;
         lavc_param_rc_buffer_aggressivity = 99;
-        lavc_param_scan_offset = CODEC_FLAG_SVCD_SCAN_OFFSET;
+        lavc_param_scan_offset = 1;
 
         break;
 
@@ -828,18 +831,35 @@ MOD_init
 
     lavc_venc_context->bit_rate           = vob->divxbitrate * 1000;
     lavc_venc_context->bit_rate_tolerance = lavc_param_vrate_tolerance * 1000;
-    lavc_venc_context->lmin= (int)(FF_QP2LAMBDA * lavc_param_lmin + 0.5);
-    lavc_venc_context->lmax= (int)(FF_QP2LAMBDA * lavc_param_lmax + 0.5);
     lavc_venc_context->max_qdiff          = lavc_param_vqdiff;
     lavc_venc_context->qcompress          = lavc_param_vqcompress;
     lavc_venc_context->qblur              = lavc_param_vqblur;
     lavc_venc_context->max_b_frames       = lavc_param_vmax_b_frames;
     lavc_venc_context->b_quant_factor     = lavc_param_vb_qfactor;
-    lavc_venc_context->rc_strategy        = lavc_param_vrc_strategy;
     lavc_venc_context->b_frame_strategy   = lavc_param_vb_strategy;
     lavc_venc_context->b_quant_offset     = lavc_param_vb_qoffset;
-    lavc_venc_context->luma_elim_threshold= lavc_param_luma_elim_threshold;
-    lavc_venc_context->chroma_elim_threshold= lavc_param_chroma_elim_threshold;
+
+    char buf[1024];
+#define set_dict_opt(val, opt) \
+	snprintf(buf, sizeof(buf), "%i", val); \
+	av_dict_set(&lavc_venc_opts, opt, buf, 0)
+#define set_dict_float_opt(val, opt) \
+	snprintf(buf, sizeof(buf), "%f", val); \
+	av_dict_set(&lavc_venc_opts, opt, buf, 0)
+    set_dict_opt(lavc_param_luma_elim_threshold, "luma_elim_threshold");
+    set_dict_opt(lavc_param_chroma_elim_threshold, "chroma_elim_threshold");
+    set_dict_opt((int)(FF_QP2LAMBDA * lavc_param_lmin + 0.5), "lmin");
+    set_dict_opt((int)(FF_QP2LAMBDA * lavc_param_lmax + 0.5), "lmax");
+    set_dict_opt(lavc_param_vrc_strategy, "rc_strategy");
+    set_dict_float_opt(lavc_param_rc_qsquish, "qsquish");
+    set_dict_float_opt(lavc_param_rc_qmod_amp, "rc_qmod_amp");
+    set_dict_opt(lavc_param_rc_qmod_freq, "rc_qmod_freq");
+    set_dict_opt(lavc_param_rc_eq, "rc_eq");
+    set_dict_opt(lavc_param_vme, "me_method");
+    set_dict_opt(lavc_param_ibias, "ibias");
+    set_dict_opt(lavc_param_pbias, "pbias");
+    set_dict_float_opt(lavc_param_rc_buffer_aggressivity, "rc_buf_aggressivity");
+    set_dict_float_opt(lavc_param_rc_initial_cplx, "rc_init_cplx");
     lavc_venc_context->rtp_payload_size   = lavc_param_packet_size;
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)   
     if (lavc_param_packet_size)
@@ -848,15 +868,9 @@ MOD_init
     lavc_venc_context->strict_std_compliance= lavc_param_strict;
     lavc_venc_context->i_quant_factor     = lavc_param_vi_qfactor;
     lavc_venc_context->i_quant_offset     = lavc_param_vi_qoffset;
-    lavc_venc_context->rc_qsquish         = lavc_param_rc_qsquish;
-    lavc_venc_context->rc_qmod_amp        = lavc_param_rc_qmod_amp;
-    lavc_venc_context->rc_qmod_freq       = lavc_param_rc_qmod_freq;
-    lavc_venc_context->rc_eq              = lavc_param_rc_eq;
     lavc_venc_context->rc_max_rate        = lavc_param_rc_max_rate * 1000;
     lavc_venc_context->rc_min_rate        = lavc_param_rc_min_rate * 1000;
     lavc_venc_context->rc_buffer_size     = lavc_param_rc_buffer_size * 1024;
-    lavc_venc_context->rc_buffer_aggressivity= lavc_param_rc_buffer_aggressivity;
-    lavc_venc_context->rc_initial_cplx    = lavc_param_rc_initial_cplx;
     lavc_venc_context->debug              = lavc_param_debug;
     lavc_venc_context->last_predictor_count= lavc_param_last_pred;
     lavc_venc_context->pre_me             = lavc_param_pre_me;
@@ -864,13 +878,11 @@ MOD_init
     lavc_venc_context->pre_dia_size       = lavc_param_pre_dia_size;
     lavc_venc_context->me_subpel_quality  = lavc_param_me_subpel_quality;
     lavc_venc_context->me_range           = lavc_param_me_range;
-    lavc_venc_context->intra_quant_bias   = lavc_param_ibias;
-    lavc_venc_context->inter_quant_bias   = lavc_param_pbias;
     lavc_venc_context->coder_type         = lavc_param_coder;
     lavc_venc_context->context_model      = lavc_param_context;
     lavc_venc_context->scenechange_threshold= lavc_param_sc_threshold;
     lavc_venc_context->noise_reduction    = lavc_param_noise_reduction;
-    lavc_venc_context->inter_threshold    = lavc_param_inter_threshold;
+    set_dict_opt(lavc_param_inter_threshold, "inter_threshold");
     lavc_venc_context->intra_dc_precision = lavc_param_intra_dc_precision;
     lavc_venc_context->skip_top           = lavc_param_skip_top;
     lavc_venc_context->skip_bottom        = lavc_param_skip_bottom;
@@ -887,7 +899,7 @@ MOD_init
 		    lavc_venc_context->thread_count);
     }
 
-    avcodec_thread_init(lavc_venc_context, lavc_param_threads);
+    lavc_venc_context->thread_count = lavc_param_threads;
 
     if (lavc_param_intra_matrix) {
         char *tmp;
@@ -1061,19 +1073,20 @@ MOD_init
     lavc_venc_context->ildct_cmp  = lavc_param_ildct_cmp;
     lavc_venc_context->dia_size   = lavc_param_dia_size;
     lavc_venc_context->flags |= lavc_param_qpel;
-    lavc_venc_context->flags |= lavc_param_gmc;
+    if(lavc_param_gmc)
+        av_dict_set(&lavc_venc_opts, "gmc", "1", 0);
     lavc_venc_context->flags |= lavc_param_closedgop;
     lavc_venc_context->flags |= lavc_param_trunc;
     lavc_venc_context->flags |= lavc_param_aic;
-    lavc_venc_context->flags |= lavc_param_umv;
     lavc_venc_context->flags |= lavc_param_v4mv;
-    lavc_venc_context->flags |= lavc_param_data_partitioning;
-    lavc_venc_context->flags |= lavc_param_cbp;
-    lavc_venc_context->flags |= lavc_param_mv0;
-    lavc_venc_context->flags |= lavc_param_qp_rd;
-    lavc_venc_context->flags |= lavc_param_scan_offset;
-    lavc_venc_context->flags |= lavc_param_ss;
-    lavc_venc_context->flags |= lavc_param_alt;
+    if(lavc_param_cbp)
+    	av_dict_set(&lavc_venc_opts, "mpv_flags", "+cbp_rd", 0);
+    if(lavc_param_mv0)
+        av_dict_set(&lavc_venc_opts, "mpv_flags", "+mv0", 0);
+    if(lavc_param_qp_rd)
+    	av_dict_set(&lavc_venc_opts, "mpv_flags", "+qp_rd", 0);
+    if (lavc_param_normalize_aqp)
+    	av_dict_set(&lavc_venc_opts, "mpv_flags", "+naq", 0);
     lavc_venc_context->flags |= lavc_param_ilme;
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)   
     lavc_venc_context->flags |= lavc_param_trell;
@@ -1082,9 +1095,7 @@ MOD_init
 #endif
 
     if (lavc_param_gray)
-        lavc_venc_context->flags |= CODEC_FLAG_GRAY;
-    if (lavc_param_normalize_aqp)
-        lavc_venc_context->flags |= CODEC_FLAG_NORMALIZE_AQP;
+        lavc_venc_context->flags |= AV_CODEC_FLAG_GRAY;
 
     switch(vob->encode_fields) {
     case TC_ENCODE_FIELDS_TOP_FIRST:
@@ -1102,9 +1113,9 @@ MOD_init
     }
 
     lavc_venc_context->flags |= interlacing_active ?
-        CODEC_FLAG_INTERLACED_DCT : 0;
+        AV_CODEC_FLAG_INTERLACED_DCT : 0;
     lavc_venc_context->flags |= interlacing_active ?
-        CODEC_FLAG_INTERLACED_ME : 0;
+        AV_CODEC_FLAG_INTERLACED_ME : 0;
 
     lavc_venc_context->flags |= lavc_param_psnr;
     do_psnr = lavc_param_psnr;
@@ -1112,7 +1123,7 @@ MOD_init
     lavc_venc_context->prediction_method = lavc_param_prediction_method;
 
     if(is_huffyuv)
-        lavc_venc_context->pix_fmt = PIX_FMT_YUV422P;
+        lavc_venc_context->pix_fmt = AV_PIX_FMT_YUV422P;
     else
     {
         switch(pix_fmt)
@@ -1121,18 +1132,18 @@ MOD_init
             case CODEC_RGB:
             {
                 if(is_mjpeg)
-                    lavc_venc_context->pix_fmt = PIX_FMT_YUVJ420P;
+                    lavc_venc_context->pix_fmt = AV_PIX_FMT_YUVJ420P;
                 else
-                    lavc_venc_context->pix_fmt = PIX_FMT_YUV420P;
+                    lavc_venc_context->pix_fmt = AV_PIX_FMT_YUV420P;
                 break;
             }
 
             case CODEC_YUV422:
             {
                 if(is_mjpeg)
-                    lavc_venc_context->pix_fmt = PIX_FMT_YUVJ422P;
+                    lavc_venc_context->pix_fmt = AV_PIX_FMT_YUVJ422P;
                 else
-                    lavc_venc_context->pix_fmt = PIX_FMT_YUV422P;
+                    lavc_venc_context->pix_fmt = AV_PIX_FMT_YUV422P;
                 break;
             }
 
@@ -1151,7 +1162,7 @@ MOD_init
                   "encoding.");
           return TC_EXPORT_ERROR;
         }
-        lavc_venc_context->flags |= CODEC_FLAG_PASS1;
+        lavc_venc_context->flags |= AV_CODEC_FLAG_PASS1;
         stats_file = fopen(vob->divxlogfile, "w");
         if (stats_file == NULL){
           tc_log_warn(MOD_NAME, "Could not create 2pass log file \"%s\".",
@@ -1165,7 +1176,7 @@ MOD_init
                   "encoding.");
           return TC_EXPORT_ERROR;
         }
-        lavc_venc_context->flags |= CODEC_FLAG_PASS2;
+        lavc_venc_context->flags |= AV_CODEC_FLAG_PASS2;
         stats_file= fopen(vob->divxlogfile, "r");
         if (stats_file==NULL){
           tc_log_warn(MOD_NAME, "Could not open 2pass log file \"%s\" for "
@@ -1196,16 +1207,14 @@ MOD_init
         break;
       case 3:
         /* fixed qscale :p */
-        lavc_venc_context->flags   |= CODEC_FLAG_QSCALE;
+        lavc_venc_context->flags   |= AV_CODEC_FLAG_QSCALE;
         lavc_venc_frame->quality  = vob->divxbitrate;
         break;
     }
 
-    lavc_venc_context->me_method = ME_ZERO + lavc_param_vme;
-
 
 	/* FIXME: transcode itself contains "broken ffmpeg default settings", thus we need to override them! */
-	if (lavc_param_video_preset) {
+	if (lavc_param_video_preset && strcmp(lavc_param_video_preset, "none")) {
 		avcodec_opts[AVMEDIA_TYPE_VIDEO] = lavc_venc_context;
 		video_codec_name = ffmpeg_codec_name(codec->name);
 
@@ -1241,20 +1250,39 @@ MOD_init
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
 
@@ -1574,6 +1602,8 @@ MOD_encode
 
   int out_size;
   const char pict_type_char[5]= {'?', 'I', 'P', 'B', 'S'};
+  AVPacket pkt;
+  int ret, got_packet = 0;
 
   if (param->flag == TC_VIDEO) {
 
@@ -1598,7 +1628,7 @@ MOD_encode
 	        	YUV_INIT_PLANES(src, param->buffer, IMG_YUV_DEFAULT,
 			                	lavc_venc_context->width, lavc_venc_context->height);
                 avpicture_fill((AVPicture *)lavc_venc_frame, img_buffer,
-                               PIX_FMT_YUV422P, lavc_venc_context->width,
+                               AV_PIX_FMT_YUV422P, lavc_venc_context->width,
                                lavc_venc_context->height);
         		/* FIXME: can't use tcv_convert (see decode_lavc.c) */
                 ac_imgconvert(src, IMG_YUV_DEFAULT,
@@ -1628,7 +1658,7 @@ MOD_encode
 		                		lavc_venc_context->width,
                                 lavc_venc_context->height);
                 avpicture_fill((AVPicture *)lavc_venc_frame, img_buffer,
-                               PIX_FMT_YUV420P, lavc_venc_context->width,
+                               AV_PIX_FMT_YUV420P, lavc_venc_context->width,
                                lavc_venc_context->height);
                 ac_imgconvert(src, IMG_YUV422P,
                               lavc_venc_frame->data, IMG_YUV420P,
@@ -1639,7 +1669,7 @@ MOD_encode
 
         case CODEC_RGB:
             avpicture_fill((AVPicture *)lavc_venc_frame, img_buffer,
-                           PIX_FMT_YUV420P, lavc_venc_context->width,
+                           AV_PIX_FMT_YUV420P, lavc_venc_context->width,
                            lavc_venc_context->height);
     	    ac_imgconvert(&param->buffer, IMG_RGB_DEFAULT,
                               lavc_venc_frame->data, IMG_YUV420P,
@@ -1652,13 +1682,17 @@ MOD_encode
               return TC_EXPORT_ERROR;
     }
 
+    av_init_packet(&pkt);
+    pkt.data = enc_buffer;
+    pkt.size = size;
 
     TC_LOCK_LIBAVCODEC;
-    out_size = avcodec_encode_video(lavc_venc_context,
-                                    enc_buffer, size,
-                                    lavc_venc_frame);
+    ret = avcodec_encode_video2(lavc_venc_context, &pkt,
+                                    lavc_venc_frame, &got_packet);
     TC_UNLOCK_LIBAVCODEC;
 
+    out_size = ret ? ret : pkt.size;
+
     if (out_size < 0) {
       tc_log_warn(MOD_NAME, "encoder error: size (%d)", out_size);
       return TC_EXPORT_ERROR;
