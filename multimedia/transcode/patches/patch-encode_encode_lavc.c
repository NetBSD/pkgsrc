$NetBSD: patch-encode_encode_lavc.c,v 1.3 2019/12/29 10:23:53 markd Exp $

Fixes building against FFmpeg version >= 4.0.0 (gentoo patch).

--- encode/encode_lavc.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ encode/encode_lavc.c
@@ -74,6 +74,16 @@ struct tclavcconfigdata_ {
     int lmin;
     int lmax;
     int me_method;
+    int luma_elim_threshold;
+    int chroma_elim_threshold;
+    int quantizer_noise_shaping;
+    int inter_quant_bias;
+    int intra_quant_bias;
+    int scenechange_factor;
+    int rc_strategy;
+    float rc_initial_cplx;
+    float rc_qsquish;
+    float border_masking;
 
     /* same as above for flags */
     struct {
@@ -114,6 +124,7 @@ struct tclavcprivatedata_ {
 
     AVFrame ff_venc_frame;
     AVCodecContext ff_vcontext;
+    AVDictionary * ff_opts;
 
     AVCodec *ff_vcodec;
 
@@ -164,6 +175,7 @@ static const TCCodecID tc_lavc_codecs_ou
     TC_CODEC_ERROR
 };
 
+#if LIBAVCODEC_VERSION_MAJOR < 55
 static const enum CodecID tc_lavc_internal_codecs[] = {
     CODEC_ID_MPEG1VIDEO, CODEC_ID_MPEG2VIDEO, CODEC_ID_MPEG4,
     CODEC_ID_H263I, CODEC_ID_H263P,
@@ -176,6 +188,20 @@ static const enum CodecID tc_lavc_intern
     CODEC_ID_MSMPEG4V2, CODEC_ID_MSMPEG4V3,
     CODEC_ID_NONE
 };
+#else
+static const enum AVCodecID tc_lavc_internal_codecs[] = {
+    AV_CODEC_ID_MPEG1VIDEO, AV_CODEC_ID_MPEG2VIDEO, AV_CODEC_ID_MPEG4,
+    AV_CODEC_ID_H263I, AV_CODEC_ID_H263P,
+    AV_CODEC_ID_H264,
+    AV_CODEC_ID_WMV1, AV_CODEC_ID_WMV2,
+    AV_CODEC_ID_RV10,
+    AV_CODEC_ID_HUFFYUV, AV_CODEC_ID_FFV1,
+    AV_CODEC_ID_DVVIDEO,
+    AV_CODEC_ID_MJPEG, AV_CODEC_ID_LJPEG,
+    AV_CODEC_ID_MSMPEG4V2, AV_CODEC_ID_MSMPEG4V3,
+    AV_CODEC_ID_NONE
+};
+#endif
 
 static const TCFormatID tc_lavc_formats[] = { TC_FORMAT_ERROR };
 
@@ -214,7 +240,7 @@ static void pre_encode_video_yuv420p(TCL
                                      vframe_list_t *vframe)
 {
     avpicture_fill((AVPicture *)&pd->ff_venc_frame, vframe->video_buf,
-                    PIX_FMT_YUV420P,
+                    AV_PIX_FMT_YUV420P,
                     pd->ff_vcontext.width, pd->ff_vcontext.height);
 }
 
@@ -228,7 +254,7 @@ static void pre_encode_video_yuv420p_huf
                     IMG_YUV_DEFAULT,
                     pd->ff_vcontext.width, pd->ff_vcontext.height);
     avpicture_fill((AVPicture *)&pd->ff_venc_frame, pd->vframe_buf->video_buf,
-                   PIX_FMT_YUV422P,
+                   AV_PIX_FMT_YUV422P,
                    pd->ff_vcontext.width, pd->ff_vcontext.height);
     ac_imgconvert(src, IMG_YUV_DEFAULT,
                   pd->ff_venc_frame.data, IMG_YUV422P,
@@ -244,7 +270,7 @@ static void pre_encode_video_yuv422p(TCL
                     IMG_YUV422P,
                     pd->ff_vcontext.width, pd->ff_vcontext.height);
     avpicture_fill((AVPicture *)&pd->ff_venc_frame, pd->vframe_buf->video_buf,
-                   PIX_FMT_YUV420P,
+                   AV_PIX_FMT_YUV420P,
                    pd->ff_vcontext.width, pd->ff_vcontext.height);
     ac_imgconvert(src, IMG_YUV422P,
                   pd->ff_venc_frame.data, IMG_YUV420P,
@@ -256,7 +282,7 @@ static void pre_encode_video_yuv422p_huf
                                              vframe_list_t *vframe)
 {
     avpicture_fill((AVPicture *)&pd->ff_venc_frame, vframe->video_buf,
-                   PIX_FMT_YUV422P,
+                   AV_PIX_FMT_YUV422P,
                    pd->ff_vcontext.width, pd->ff_vcontext.height);
 
 }
@@ -266,7 +292,7 @@ static void pre_encode_video_rgb24(TCLav
                                    vframe_list_t *vframe)
 {
     avpicture_fill((AVPicture *)&pd->ff_venc_frame, pd->vframe_buf->video_buf,
-                   PIX_FMT_YUV420P,
+                   AV_PIX_FMT_YUV420P,
                    pd->ff_vcontext.width, pd->ff_vcontext.height);
     ac_imgconvert(&vframe->video_buf, IMG_RGB_DEFAULT,
                   pd->ff_venc_frame.data, IMG_YUV420P,
@@ -591,21 +617,21 @@ static int tc_lavc_set_pix_fmt(TCLavcPri
       case CODEC_YUV:
         if (TC_VCODEC_ID(pd) == TC_CODEC_HUFFYUV) {
             pd->tc_pix_fmt = TC_CODEC_YUV422P;
-            pd->ff_vcontext.pix_fmt = PIX_FMT_YUV422P;
+            pd->ff_vcontext.pix_fmt = AV_PIX_FMT_YUV422P;
             pd->pre_encode_video = pre_encode_video_yuv420p_huffyuv;
         } else {
             pd->tc_pix_fmt = TC_CODEC_YUV420P;
             pd->ff_vcontext.pix_fmt = (TC_VCODEC_ID(pd) == TC_CODEC_MJPEG) 
-                                       ? PIX_FMT_YUVJ420P
-                                       : PIX_FMT_YUV420P;
+                                       ? AV_PIX_FMT_YUVJ420P
+                                       : AV_PIX_FMT_YUV420P;
             pd->pre_encode_video = pre_encode_video_yuv420p;
         }
         break;
       case CODEC_YUV422:
         pd->tc_pix_fmt = TC_CODEC_YUV422P;
         pd->ff_vcontext.pix_fmt = (TC_VCODEC_ID(pd) == TC_CODEC_MJPEG) 
-                                   ? PIX_FMT_YUVJ422P
-                                   : PIX_FMT_YUV422P;
+                                   ? AV_PIX_FMT_YUVJ422P
+                                   : AV_PIX_FMT_YUV422P;
         if (TC_VCODEC_ID(pd) == TC_CODEC_HUFFYUV) {
             pd->pre_encode_video = pre_encode_video_yuv422p_huffyuv;
         } else {
@@ -615,10 +641,10 @@ static int tc_lavc_set_pix_fmt(TCLavcPri
       case CODEC_RGB:
         pd->tc_pix_fmt = TC_CODEC_RGB;
         pd->ff_vcontext.pix_fmt = (TC_VCODEC_ID(pd) == TC_CODEC_HUFFYUV)
-                                        ? PIX_FMT_YUV422P
+                                        ? AV_PIX_FMT_YUV422P
                                         : (TC_VCODEC_ID(pd) == TC_CODEC_MJPEG) 
-                                           ? PIX_FMT_YUVJ420P
-                                           : PIX_FMT_YUV420P;
+                                           ? AV_PIX_FMT_YUVJ420P
+                                           : AV_PIX_FMT_YUV420P;
         pd->pre_encode_video = pre_encode_video_rgb24;
         break;
       default:
@@ -665,7 +691,7 @@ static int tc_lavc_init_multipass(TCLavc
     switch (vob->divxmultipass) {
       case 1:
         CAN_DO_MULTIPASS(multipass_flag);
-        pd->ff_vcontext.flags |= CODEC_FLAG_PASS1;
+        pd->ff_vcontext.flags |= AV_CODEC_FLAG_PASS1;
         pd->stats_file = fopen(vob->divxlogfile, "w");
         if (pd->stats_file == NULL) {
             tc_log_error(MOD_NAME, "could not create 2pass log file"
@@ -675,7 +701,7 @@ static int tc_lavc_init_multipass(TCLavc
         break;
       case 2:
         CAN_DO_MULTIPASS(multipass_flag);
-        pd->ff_vcontext.flags |= CODEC_FLAG_PASS2;
+        pd->ff_vcontext.flags |= AV_CODEC_FLAG_PASS2;
         pd->stats_file = fopen(vob->divxlogfile, "r");
         if (pd->stats_file == NULL){
             tc_log_error(MOD_NAME, "could not open 2pass log file \"%s\""
@@ -704,7 +730,7 @@ static int tc_lavc_init_multipass(TCLavc
         break;
       case 3:
         /* fixed qscale :p */
-        pd->ff_vcontext.flags |= CODEC_FLAG_QSCALE;
+        pd->ff_vcontext.flags |= AV_CODEC_FLAG_QSCALE;
         pd->ff_venc_frame.quality = vob->divxbitrate;
         break;
     }
@@ -937,7 +963,11 @@ static int tc_lavc_settings_from_vob(TCL
 static void tc_lavc_config_defaults(TCLavcPrivateData *pd)
 {
     /* first of all reinitialize lavc data */
+#if LIBAVCODEC_VERSION_MAJOR < 55
     avcodec_get_context_defaults(&pd->ff_vcontext);
+#else
+    avcodec_get_context_defaults3(&pd->ff_vcontext, NULL);
+#endif
 
     pd->confdata.thread_count = 1;
 
@@ -947,7 +977,7 @@ static void tc_lavc_config_defaults(TCLa
     pd->confdata.rc_buffer_size  = 0;
     pd->confdata.lmin            = 2;
     pd->confdata.lmax            = 31;
-    pd->confdata.me_method       = ME_EPZS;
+    pd->confdata.me_method       = 0;
 
     memset(&pd->confdata.flags, 0, sizeof(pd->confdata.flags));
     pd->confdata.turbo_setup = 0;
@@ -955,19 +985,17 @@ static void tc_lavc_config_defaults(TCLa
     /* 
      * context *transcode* (not libavcodec) defaults
      */
-    pd->ff_vcontext.mb_qmin                 = 2;
-    pd->ff_vcontext.mb_qmax                 = 31;
     pd->ff_vcontext.max_qdiff               = 3;
     pd->ff_vcontext.max_b_frames            = 0;
     pd->ff_vcontext.me_range                = 0;
     pd->ff_vcontext.mb_decision             = 0;
     pd->ff_vcontext.scenechange_threshold   = 0;
-    pd->ff_vcontext.scenechange_factor      = 1;
+    pd->confdata.scenechange_factor         = 1;
     pd->ff_vcontext.b_frame_strategy        = 0;
     pd->ff_vcontext.b_sensitivity           = 40;
     pd->ff_vcontext.brd_scale               = 0;
     pd->ff_vcontext.bidir_refine            = 0;
-    pd->ff_vcontext.rc_strategy             = 2;
+    pd->confdata.rc_strategy                = 2;
     pd->ff_vcontext.b_quant_factor          = 1.25;
     pd->ff_vcontext.i_quant_factor          = 0.8;
     pd->ff_vcontext.b_quant_offset          = 1.25;
@@ -975,10 +1003,10 @@ static void tc_lavc_config_defaults(TCLa
     pd->ff_vcontext.qblur                   = 0.5;
     pd->ff_vcontext.qcompress               = 0.5;
     pd->ff_vcontext.mpeg_quant              = 0;
-    pd->ff_vcontext.rc_initial_cplx         = 0.0;
-    pd->ff_vcontext.rc_qsquish              = 1.0;
-    pd->ff_vcontext.luma_elim_threshold     = 0;
-    pd->ff_vcontext.chroma_elim_threshold   = 0;
+    pd->confdata.rc_initial_cplx            = 0.0;
+    pd->confdata.rc_qsquish              = 1.0;
+    pd->confdata.luma_elim_threshold     = 0;
+    pd->confdata.chroma_elim_threshold   = 0;
     pd->ff_vcontext.strict_std_compliance   = 0;
     pd->ff_vcontext.dct_algo                = FF_DCT_AUTO;
     pd->ff_vcontext.idct_algo               = FF_IDCT_AUTO;
@@ -987,7 +1015,7 @@ static void tc_lavc_config_defaults(TCLa
     pd->ff_vcontext.temporal_cplx_masking   = 0.0;
     pd->ff_vcontext.spatial_cplx_masking    = 0.0;
     pd->ff_vcontext.p_masking               = 0.0;
-    pd->ff_vcontext.border_masking          = 0.0;
+    pd->confdata.border_masking          = 0.0;
     pd->ff_vcontext.me_pre_cmp              = 0;
     pd->ff_vcontext.me_cmp                  = 0;
     pd->ff_vcontext.me_sub_cmp              = 0;
@@ -999,10 +1027,8 @@ static void tc_lavc_config_defaults(TCLa
     pd->ff_vcontext.pre_me                  = 1;
     pd->ff_vcontext.me_subpel_quality       = 8;
     pd->ff_vcontext.refs                    = 1;
-    pd->ff_vcontext.intra_quant_bias        = FF_DEFAULT_QUANT_BIAS;
-    pd->ff_vcontext.inter_quant_bias        = FF_DEFAULT_QUANT_BIAS;
     pd->ff_vcontext.noise_reduction         = 0;
-    pd->ff_vcontext.quantizer_noise_shaping = 0;
+    pd->confdata.quantizer_noise_shaping = 0;
     pd->ff_vcontext.flags                   = 0;
 }
 
@@ -1023,27 +1049,22 @@ static void tc_lavc_config_defaults(TCLa
  */
 static void tc_lavc_dispatch_settings(TCLavcPrivateData *pd)
 {
+    char buf[1024];
     /* some translation... */
     pd->ff_vcontext.bit_rate_tolerance = pd->confdata.vrate_tolerance * 1000;
     pd->ff_vcontext.rc_min_rate = pd->confdata.rc_min_rate * 1000;
     pd->ff_vcontext.rc_max_rate = pd->confdata.rc_max_rate * 1000;
     pd->ff_vcontext.rc_buffer_size = pd->confdata.rc_buffer_size * 1024;
-    pd->ff_vcontext.lmin = (int)(FF_QP2LAMBDA * pd->confdata.lmin + 0.5);
-    pd->ff_vcontext.lmax = (int)(FF_QP2LAMBDA * pd->confdata.lmax + 0.5);
-    pd->ff_vcontext.me_method = ME_ZERO + pd->confdata.me_method;
+    snprintf(buf, sizeof(buf), "%i", (int)(FF_QP2LAMBDA * pd->confdata.lmin + 0.5));
+    av_dict_set(&(pd->ff_opts), "lmin", buf, 0);
+    snprintf(buf, sizeof(buf), "%i", (int)(FF_QP2LAMBDA * pd->confdata.lmax + 0.5));
+    av_dict_set(&(pd->ff_opts), "lmax", buf, 0);
 
     pd->ff_vcontext.flags = 0;
-    SET_FLAG(pd, mv0);
-    SET_FLAG(pd, cbp);
     SET_FLAG(pd, qpel);
-    SET_FLAG(pd, alt);
-    SET_FLAG(pd, vdpart);
-    SET_FLAG(pd, naq);
     SET_FLAG(pd, ilme);
     SET_FLAG(pd, ildct);
     SET_FLAG(pd, aic);
-    SET_FLAG(pd, aiv);
-    SET_FLAG(pd, umv);
     SET_FLAG(pd, psnr);
     SET_FLAG(pd, trell);
     SET_FLAG(pd, gray);
@@ -1061,9 +1082,49 @@ static void tc_lavc_dispatch_settings(TC
     }
     if (pd->interlacing.active) {
         /* enforce interlacing */
-        pd->ff_vcontext.flags |= CODEC_FLAG_INTERLACED_DCT;
-        pd->ff_vcontext.flags |= CODEC_FLAG_INTERLACED_ME;
+        pd->ff_vcontext.flags |= AV_CODEC_FLAG_INTERLACED_DCT;
+        pd->ff_vcontext.flags |= AV_CODEC_FLAG_INTERLACED_ME;
     }
+    if (pd->confdata.flags.alt) {
+        av_dict_set(&(pd->ff_opts), "alternate_scan", "1", 0);
+    }
+    if (pd->confdata.flags.vdpart) {
+        av_dict_set(&(pd->ff_opts), "data_partitioning", "1", 0);
+    }
+    if (pd->confdata.flags.umv) {
+        av_dict_set(&(pd->ff_opts), "umv", "1", 0);
+    }
+    if (pd->confdata.flags.aiv) {
+        av_dict_set(&(pd->ff_opts), "aiv", "1", 0);
+    }
+    if (pd->confdata.flags.cbp) {
+    	av_dict_set(&(pd->ff_opts), "mpv_flags", "+cbp_rd", 0);
+    }
+    if (pd->confdata.flags.mv0) {
+        av_dict_set(&(pd->ff_opts), "mpv_flags", "+mv0", 0);
+    }
+    if (pd->confdata.flags.naq) {
+        av_dict_set(&(pd->ff_opts), "mpv_flags", "+naq", 0);
+    }
+
+#define set_dict_opt(val, opt) \
+    snprintf(buf, sizeof(buf), "%i", pd->confdata.val);\
+    av_dict_set(&(pd->ff_opts), opt, buf, 0)
+#define set_dict_float_opt(val, opt) \
+    snprintf(buf, sizeof(buf), "%f", pd->confdata.val);\
+    av_dict_set(&(pd->ff_opts), opt, buf, 0)
+
+    set_dict_opt(luma_elim_threshold, "luma_elim_threshold");
+    set_dict_opt(chroma_elim_threshold, "chroma_elim_threshold");
+    set_dict_opt(quantizer_noise_shaping, "quantizer_noise_shaping");
+    set_dict_opt(inter_quant_bias, "pbias");
+    set_dict_opt(intra_quant_bias, "ibias");
+    set_dict_opt(me_method, "me_method");
+    set_dict_opt(scenechange_factor, "sc_factor");
+    set_dict_opt(rc_strategy, "rc_strategy");
+    set_dict_float_opt(rc_initial_cplx, "rc_init_cplx");
+    set_dict_float_opt(rc_qsquish, "qsquish");
+    set_dict_float_opt(border_masking, "border_mask");
 }
 
 #undef SET_FLAG
@@ -1116,17 +1177,15 @@ static int tc_lavc_read_config(TCLavcPri
         //  handled by transcode core
         //  { "vqmax", PCTX(qmax), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 60 },
         //  handled by transcode core
-        { "mbqmin", PCTX(mb_qmin), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 60 },
-        { "mbqmax", PCTX(mb_qmax), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 60 },
         { "lmin", PAUX(lmin), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.01, 255.0 },
         { "lmax", PAUX(lmax), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.01, 255.0 },
         { "vqdiff", PCTX(max_qdiff), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 31 },
-        { "vmax_b_frames", PCTX(max_b_frames), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, FF_MAX_B_FRAMES },
+        { "vmax_b_frames", PCTX(max_b_frames), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, INT_MAX },
         { "vme", PAUX(me_method), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 16, },
         { "me_range", PCTX(me_range), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 16000 },
         { "mbd", PCTX(mb_decision), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 3 },
         { "sc_threshold", PCTX(scenechange_threshold), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -1000000, 1000000 },
-        { "sc_factor", PCTX(scenechange_factor), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 16 },
+        { "sc_factor", PAUX(scenechange_factor), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 16 },
         { "vb_strategy", PCTX(b_frame_strategy), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 10 },
         { "b_sensitivity", PCTX(b_sensitivity), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 100 },
         { "brd_scale", PCTX(brd_scale), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 10 },
@@ -1137,7 +1196,7 @@ static int tc_lavc_read_config(TCLavcPri
         { "vrc_maxrate", PAUX(rc_max_rate), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 24000000 },
         { "vrc_minrate", PAUX(rc_min_rate), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 24000000 },
         { "vrc_buf_size", PAUX(rc_buffer_size), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 4, 24000000 },
-        { "vrc_strategy", PCTX(rc_strategy), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 2 },
+        { "vrc_strategy", PAUX(rc_strategy), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 2 },
         { "vb_qfactor", PCTX(b_quant_factor), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, -31.0, 31.0 },
         { "vi_qfactor", PCTX(i_quant_factor), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, -31.0, 31.0 },
         { "vb_qoffset", PCTX(b_quant_offset), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.0, 31.0 },
@@ -1147,11 +1206,11 @@ static int tc_lavc_read_config(TCLavcPri
         { "mpeg_quant", PCTX(mpeg_quant), TCCONF_TYPE_FLAG, 0, 0, 1 },
         //  { "vrc_eq",     }, // not yet supported
         { "vrc_override", rc_override_buf, TCCONF_TYPE_STRING, 0, 0, 0 },
-        { "vrc_init_cplx", PCTX(rc_initial_cplx), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.0, 9999999.0 },
+        { "vrc_init_cplx", PAUX(rc_initial_cplx), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.0, 9999999.0 },
         //  { "vrc_init_occupancy",   }, // not yet supported
-        { "vqsquish", PCTX(rc_qsquish), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.0, 99.0 },
-        { "vlelim", PCTX(luma_elim_threshold), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -99, 99 },
-        { "vcelim", PCTX(chroma_elim_threshold), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -99, 99 },
+        { "vqsquish", PAUX(rc_qsquish), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.0, 99.0 },
+        { "vlelim", PAUX(luma_elim_threshold), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -99, 99 },
+        { "vcelim", PAUX(chroma_elim_threshold), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -99, 99 },
         { "vstrict", PCTX(strict_std_compliance), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -99, 99 },
         { "vpsize", PCTX(rtp_payload_size), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 100000000 },
         { "dct", PCTX(dct_algo), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 10 },
@@ -1161,7 +1220,7 @@ static int tc_lavc_read_config(TCLavcPri
         { "tcplx_mask", PCTX(temporal_cplx_masking), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.0, 1.0 },
         { "scplx_mask", PCTX(spatial_cplx_masking), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.0, 1.0 },
         { "p_mask", PCTX(p_masking), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.0, 1.0 },
-        { "border_mask", PCTX(border_masking), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.0, 1.0 },
+        { "border_mask", PAUX(border_masking), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.0, 1.0 },
         { "pred", PCTX(prediction_method), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 4 },
         { "precmp", PCTX(me_pre_cmp), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 2000 },
         { "cmp", PCTX(me_cmp), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 2000 },
@@ -1174,37 +1233,37 @@ static int tc_lavc_read_config(TCLavcPri
         { "pre_me", PCTX(pre_me), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 2000},
         { "subq", PCTX(me_subpel_quality), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 8 },
         { "refs", PCTX(refs), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 8 },
-        { "ibias", PCTX(intra_quant_bias), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -512, 512 },
-        { "pbias", PCTX(inter_quant_bias), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -512, 512 },
+        { "ibias", PAUX(intra_quant_bias), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -512, 512 },
+        { "pbias", PAUX(inter_quant_bias), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -512, 512 },
         { "nr", PCTX(noise_reduction), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 1000000},
-        { "qns", PCTX(quantizer_noise_shaping), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 3 },
+        { "qns", PAUX(quantizer_noise_shaping), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 3 },
         { "inter_matrix_file", inter_matrix_file, TCCONF_TYPE_STRING, 0, 0, 0 },
         { "intra_matrix_file", intra_matrix_file, TCCONF_TYPE_STRING, 0, 0, 0 },
     
-        { "mv0", PAUX(flags.mv0), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_MV0 },
-        { "cbp", PAUX(flags.cbp), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_CBP_RD },
-        { "qpel", PAUX(flags.qpel), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_QPEL },
-        { "alt", PAUX(flags.alt), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_ALT_SCAN },
-        { "ilme", PAUX(flags.ilme), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_INTERLACED_ME },
-        { "ildct", PAUX(flags.ildct), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_INTERLACED_DCT },
-        { "naq", PAUX(flags.naq), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_NORMALIZE_AQP },
-        { "vdpart", PAUX(flags.vdpart), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_PART },
+        { "mv0", PAUX(flags.mv0), TCCONF_TYPE_FLAG, 0, 0, 1 },
+        { "cbp", PAUX(flags.cbp), TCCONF_TYPE_FLAG, 0, 0, 1 },
+        { "qpel", PAUX(flags.qpel), TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_QPEL },
+        { "alt", PAUX(flags.alt), TCCONF_TYPE_FLAG, 0, 0, 1 },
+        { "ilme", PAUX(flags.ilme), TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_INTERLACED_ME },
+        { "ildct", PAUX(flags.ildct), TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_INTERLACED_DCT },
+        { "naq", PAUX(flags.naq), TCCONF_TYPE_FLAG, 0, 0, 1 },
+        { "vdpart", PAUX(flags.vdpart), TCCONF_TYPE_FLAG, 0, 0, 1 },
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)
         { "aic", PAUX(flags.aic), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_H263P_AIC },
 #else        
-        { "aic", PAUX(flags.aic), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_AC_PRED },
+        { "aic", PAUX(flags.aic), TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_AC_PRED },
 #endif
-        { "aiv", PAUX(flags.aiv), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_H263P_AIV },
-        { "umv", PAUX(flags.umv), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_H263P_UMV },
-        { "psnr", PAUX(flags.psnr), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_PSNR },
+        { "aiv", PAUX(flags.aiv), TCCONF_TYPE_FLAG, 0, 0, 1 },
+        { "umv", PAUX(flags.umv), TCCONF_TYPE_FLAG, 0, 0, 1 },
+        { "psnr", PAUX(flags.psnr), TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_PSNR },
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)
         { "trell", PAUX(flags.trell), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_TRELLIS_QUANT },
 #else
         { "trell", PCTX(trellis), TCCONF_TYPE_FLAG, 0, 0, 1 },
 #endif
-        { "gray", PAUX(flags.gray), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_GRAY },
-        { "v4mv", PAUX(flags.v4mv), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_4MV },
-        { "closedgop", PAUX(flags.closedgop), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_CLOSED_GOP },
+        { "gray", PAUX(flags.gray), TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_GRAY },
+        { "v4mv", PAUX(flags.v4mv), TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_4MV },
+        { "closedgop", PAUX(flags.closedgop), TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_CLOSED_GOP },
     
         //  { "turbo", PAUX(turbo_setup), TCCONF_TYPE_FLAG, 0, 0, 1 }, // not yet  supported
         /* End of the config file */
@@ -1345,12 +1404,14 @@ static int tc_lavc_configure(TCModuleIns
 
     pd = self->userdata;
 
+    pd->ff_opts = NULL;
+
     pd->flush_flag = vob->encoder_flush;
     
     /* FIXME: move into core? */
     TC_INIT_LIBAVCODEC;
 
-    avcodec_get_frame_defaults(&pd->ff_venc_frame);
+    av_frame_unref(&pd->ff_venc_frame);
     /*
      * auxiliary config data needs to be blanked too
      * before any other operation
@@ -1387,7 +1448,7 @@ static int tc_lavc_configure(TCModuleIns
                     pd->confdata.thread_count,
                     (pd->confdata.thread_count > 1) ?"s" :"");
     }
-    avcodec_thread_init(&pd->ff_vcontext, pd->confdata.thread_count);
+    pd->ff_vcontext.thread_count = pd->confdata.thread_count;
 
     pd->ff_vcodec = avcodec_find_encoder(FF_VCODEC_ID(pd));
     if (pd->ff_vcodec == NULL) {
@@ -1397,11 +1458,11 @@ static int tc_lavc_configure(TCModuleIns
     }
 
     TC_LOCK_LIBAVCODEC;
-    ret = avcodec_open(&pd->ff_vcontext, pd->ff_vcodec);
+    ret = avcodec_open2(&pd->ff_vcontext, pd->ff_vcodec, &(pd->ff_opts));
     TC_UNLOCK_LIBAVCODEC;
 
     if (ret < 0) {
-        tc_log_error(MOD_NAME, "avcodec_open() failed");
+        tc_log_error(MOD_NAME, "avcodec_open2() failed");
         goto failed;
     }
     /* finally, pass up the extradata, if any */
@@ -1483,6 +1544,8 @@ static int tc_lavc_encode_video(TCModule
                                 vframe_list_t *outframe)
 {
     TCLavcPrivateData *pd = NULL;
+    AVPacket pkt;
+    int ret, got_packet = 0;
 
     TC_MODULE_SELF_CHECK(self, "encode_video");
 
@@ -1497,12 +1560,15 @@ static int tc_lavc_encode_video(TCModule
 
     pd->pre_encode_video(pd, inframe); 
 
+    av_init_packet(&pkt);
+    pkt.data = outframe->video_buf;
+    pkt.size = inframe->video_size;
+
     TC_LOCK_LIBAVCODEC;
-    outframe->video_len = avcodec_encode_video(&pd->ff_vcontext,
-                                               outframe->video_buf,
-                                               inframe->video_size,
-                                               &pd->ff_venc_frame);
+    ret = avcodec_encode_video2(&pd->ff_vcontext,   &pkt,
+    				&pd->ff_venc_frame, &got_packet);
     TC_UNLOCK_LIBAVCODEC;
+    outframe->video_len = ret ? ret : pkt.size;
 
     if (outframe->video_len < 0) {
         tc_log_warn(MOD_NAME, "encoder error: size (%i)",
