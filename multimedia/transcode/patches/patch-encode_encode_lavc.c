$NetBSD: patch-encode_encode_lavc.c,v 1.2 2015/11/21 17:14:26 adam Exp $

Fixes building against FFmpeg version >= 2.0.0 (gentoo patch).

--- encode/encode_lavc.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ encode/encode_lavc.c
@@ -74,6 +74,9 @@ struct tclavcconfigdata_ {
     int lmin;
     int lmax;
     int me_method;
+    int luma_elim_threshold;
+    int chroma_elim_threshold;
+    int quantizer_noise_shaping;
 
     /* same as above for flags */
     struct {
@@ -114,6 +117,7 @@ struct tclavcprivatedata_ {
 
     AVFrame ff_venc_frame;
     AVCodecContext ff_vcontext;
+    AVDictionary * ff_opts;
 
     AVCodec *ff_vcodec;
 
@@ -164,6 +168,7 @@ static const TCCodecID tc_lavc_codecs_ou
     TC_CODEC_ERROR
 };
 
+#if LIBAVCODEC_VERSION_MAJOR < 55
 static const enum CodecID tc_lavc_internal_codecs[] = {
     CODEC_ID_MPEG1VIDEO, CODEC_ID_MPEG2VIDEO, CODEC_ID_MPEG4,
     CODEC_ID_H263I, CODEC_ID_H263P,
@@ -176,6 +181,20 @@ static const enum CodecID tc_lavc_intern
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
 
@@ -937,7 +956,11 @@ static int tc_lavc_settings_from_vob(TCL
 static void tc_lavc_config_defaults(TCLavcPrivateData *pd)
 {
     /* first of all reinitialize lavc data */
+#if LIBAVCODEC_VERSION_MAJOR < 55
     avcodec_get_context_defaults(&pd->ff_vcontext);
+#else
+    avcodec_get_context_defaults3(&pd->ff_vcontext, NULL);
+#endif
 
     pd->confdata.thread_count = 1;
 
@@ -955,8 +978,6 @@ static void tc_lavc_config_defaults(TCLa
     /* 
      * context *transcode* (not libavcodec) defaults
      */
-    pd->ff_vcontext.mb_qmin                 = 2;
-    pd->ff_vcontext.mb_qmax                 = 31;
     pd->ff_vcontext.max_qdiff               = 3;
     pd->ff_vcontext.max_b_frames            = 0;
     pd->ff_vcontext.me_range                = 0;
@@ -977,8 +998,8 @@ static void tc_lavc_config_defaults(TCLa
     pd->ff_vcontext.mpeg_quant              = 0;
     pd->ff_vcontext.rc_initial_cplx         = 0.0;
     pd->ff_vcontext.rc_qsquish              = 1.0;
-    pd->ff_vcontext.luma_elim_threshold     = 0;
-    pd->ff_vcontext.chroma_elim_threshold   = 0;
+    pd->confdata.luma_elim_threshold     = 0;
+    pd->confdata.chroma_elim_threshold   = 0;
     pd->ff_vcontext.strict_std_compliance   = 0;
     pd->ff_vcontext.dct_algo                = FF_DCT_AUTO;
     pd->ff_vcontext.idct_algo               = FF_IDCT_AUTO;
@@ -1002,7 +1023,7 @@ static void tc_lavc_config_defaults(TCLa
     pd->ff_vcontext.intra_quant_bias        = FF_DEFAULT_QUANT_BIAS;
     pd->ff_vcontext.inter_quant_bias        = FF_DEFAULT_QUANT_BIAS;
     pd->ff_vcontext.noise_reduction         = 0;
-    pd->ff_vcontext.quantizer_noise_shaping = 0;
+    pd->confdata.quantizer_noise_shaping = 0;
     pd->ff_vcontext.flags                   = 0;
 }
 
@@ -1034,16 +1055,11 @@ static void tc_lavc_dispatch_settings(TC
 
     pd->ff_vcontext.flags = 0;
     SET_FLAG(pd, mv0);
-    SET_FLAG(pd, cbp);
     SET_FLAG(pd, qpel);
-    SET_FLAG(pd, alt);
-    SET_FLAG(pd, vdpart);
     SET_FLAG(pd, naq);
     SET_FLAG(pd, ilme);
     SET_FLAG(pd, ildct);
     SET_FLAG(pd, aic);
-    SET_FLAG(pd, aiv);
-    SET_FLAG(pd, umv);
     SET_FLAG(pd, psnr);
     SET_FLAG(pd, trell);
     SET_FLAG(pd, gray);
@@ -1064,6 +1080,30 @@ static void tc_lavc_dispatch_settings(TC
         pd->ff_vcontext.flags |= CODEC_FLAG_INTERLACED_DCT;
         pd->ff_vcontext.flags |= CODEC_FLAG_INTERLACED_ME;
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
+
+    char buf[1024];
+#define set_dict_opt(val, opt) \
+    snprintf(buf, sizeof(buf), "%i", pd->confdata.val);\
+    av_dict_set(&(pd->ff_opts), opt, buf, 0)
+
+    set_dict_opt(luma_elim_threshold, "luma_elim_threshold");
+    set_dict_opt(chroma_elim_threshold, "chroma_elim_threshold");
+    set_dict_opt(quantizer_noise_shaping, "quantizer_noise_shaping");
 }
 
 #undef SET_FLAG
@@ -1116,8 +1156,6 @@ static int tc_lavc_read_config(TCLavcPri
         //  handled by transcode core
         //  { "vqmax", PCTX(qmax), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 60 },
         //  handled by transcode core
-        { "mbqmin", PCTX(mb_qmin), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 60 },
-        { "mbqmax", PCTX(mb_qmax), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 60 },
         { "lmin", PAUX(lmin), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.01, 255.0 },
         { "lmax", PAUX(lmax), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.01, 255.0 },
         { "vqdiff", PCTX(max_qdiff), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 31 },
@@ -1150,8 +1188,8 @@ static int tc_lavc_read_config(TCLavcPri
         { "vrc_init_cplx", PCTX(rc_initial_cplx), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.0, 9999999.0 },
         //  { "vrc_init_occupancy",   }, // not yet supported
         { "vqsquish", PCTX(rc_qsquish), TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.0, 99.0 },
-        { "vlelim", PCTX(luma_elim_threshold), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -99, 99 },
-        { "vcelim", PCTX(chroma_elim_threshold), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -99, 99 },
+        { "vlelim", PAUX(luma_elim_threshold), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -99, 99 },
+        { "vcelim", PAUX(chroma_elim_threshold), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -99, 99 },
         { "vstrict", PCTX(strict_std_compliance), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -99, 99 },
         { "vpsize", PCTX(rtp_payload_size), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 100000000 },
         { "dct", PCTX(dct_algo), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 10 },
@@ -1177,25 +1215,25 @@ static int tc_lavc_read_config(TCLavcPri
         { "ibias", PCTX(intra_quant_bias), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -512, 512 },
         { "pbias", PCTX(inter_quant_bias), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -512, 512 },
         { "nr", PCTX(noise_reduction), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 1000000},
-        { "qns", PCTX(quantizer_noise_shaping), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 3 },
+        { "qns", PAUX(quantizer_noise_shaping), TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 3 },
         { "inter_matrix_file", inter_matrix_file, TCCONF_TYPE_STRING, 0, 0, 0 },
         { "intra_matrix_file", intra_matrix_file, TCCONF_TYPE_STRING, 0, 0, 0 },
     
         { "mv0", PAUX(flags.mv0), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_MV0 },
-        { "cbp", PAUX(flags.cbp), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_CBP_RD },
+        { "cbp", PAUX(flags.cbp), TCCONF_TYPE_FLAG, 0, 0, 1 },
         { "qpel", PAUX(flags.qpel), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_QPEL },
-        { "alt", PAUX(flags.alt), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_ALT_SCAN },
+        { "alt", PAUX(flags.alt), TCCONF_TYPE_FLAG, 0, 0, 1 },
         { "ilme", PAUX(flags.ilme), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_INTERLACED_ME },
         { "ildct", PAUX(flags.ildct), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_INTERLACED_DCT },
         { "naq", PAUX(flags.naq), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_NORMALIZE_AQP },
-        { "vdpart", PAUX(flags.vdpart), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_PART },
+        { "vdpart", PAUX(flags.vdpart), TCCONF_TYPE_FLAG, 0, 0, 1 },
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)
         { "aic", PAUX(flags.aic), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_H263P_AIC },
 #else        
         { "aic", PAUX(flags.aic), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_AC_PRED },
 #endif
-        { "aiv", PAUX(flags.aiv), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_H263P_AIV },
-        { "umv", PAUX(flags.umv), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_H263P_UMV },
+        { "aiv", PAUX(flags.aiv), TCCONF_TYPE_FLAG, 0, 0, 1 },
+        { "umv", PAUX(flags.umv), TCCONF_TYPE_FLAG, 0, 0, 1 },
         { "psnr", PAUX(flags.psnr), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_PSNR },
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)
         { "trell", PAUX(flags.trell), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_TRELLIS_QUANT },
@@ -1345,6 +1383,8 @@ static int tc_lavc_configure(TCModuleIns
 
     pd = self->userdata;
 
+    pd->ff_opts = NULL;
+
     pd->flush_flag = vob->encoder_flush;
     
     /* FIXME: move into core? */
@@ -1387,7 +1427,7 @@ static int tc_lavc_configure(TCModuleIns
                     pd->confdata.thread_count,
                     (pd->confdata.thread_count > 1) ?"s" :"");
     }
-    avcodec_thread_init(&pd->ff_vcontext, pd->confdata.thread_count);
+    pd->ff_vcontext.thread_count = pd->confdata.thread_count;
 
     pd->ff_vcodec = avcodec_find_encoder(FF_VCODEC_ID(pd));
     if (pd->ff_vcodec == NULL) {
@@ -1397,11 +1437,11 @@ static int tc_lavc_configure(TCModuleIns
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
