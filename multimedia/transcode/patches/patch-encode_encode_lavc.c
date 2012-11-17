$NetBSD: patch-encode_encode_lavc.c,v 1.1 2012/11/17 21:46:44 markd Exp $

Fix build with ffmpeg 0.11. gentoo patch from Brennan Shacklett

--- encode/encode_lavc.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ encode/encode_lavc.c
@@ -114,6 +114,7 @@ struct tclavcprivatedata_ {
 
     AVFrame ff_venc_frame;
     AVCodecContext ff_vcontext;
+    AVDictionary ** ff_opts;
 
     AVCodec *ff_vcodec;
 
@@ -1036,14 +1037,10 @@ static void tc_lavc_dispatch_settings(TC
     SET_FLAG(pd, mv0);
     SET_FLAG(pd, cbp);
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
@@ -1064,6 +1061,18 @@ static void tc_lavc_dispatch_settings(TC
         pd->ff_vcontext.flags |= CODEC_FLAG_INTERLACED_DCT;
         pd->ff_vcontext.flags |= CODEC_FLAG_INTERLACED_ME;
     }
+    if (pd->confdata.flags.alt) {
+        av_dict_set(pd->ff_opts, "alternate_scan", "1", 0);
+    }
+    if (pd->confdata.flags.vdpart) {
+        av_dict_set(pd->ff_opts, "data_partitioning", "1", 0);
+    }
+    if (pd->confdata.flags.umv) {
+        av_dict_set(pd->ff_opts, "umv", "1", 0);
+    }
+    if (pd->confdata.flags.aiv) {
+        av_dict_set(pd->ff_opts, "aiv", "1", 0);
+    }
 }
 
 #undef SET_FLAG
@@ -1184,18 +1193,18 @@ static int tc_lavc_read_config(TCLavcPri
         { "mv0", PAUX(flags.mv0), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_MV0 },
         { "cbp", PAUX(flags.cbp), TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_CBP_RD },
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
@@ -1387,7 +1396,7 @@ static int tc_lavc_configure(TCModuleIns
                     pd->confdata.thread_count,
                     (pd->confdata.thread_count > 1) ?"s" :"");
     }
-    avcodec_thread_init(&pd->ff_vcontext, pd->confdata.thread_count);
+    pd->ff_vcontext.thread_count = pd->confdata.thread_count;
 
     pd->ff_vcodec = avcodec_find_encoder(FF_VCODEC_ID(pd));
     if (pd->ff_vcodec == NULL) {
@@ -1397,11 +1406,11 @@ static int tc_lavc_configure(TCModuleIns
     }
 
     TC_LOCK_LIBAVCODEC;
-    ret = avcodec_open(&pd->ff_vcontext, pd->ff_vcodec);
+    ret = avcodec_open2(&pd->ff_vcontext, pd->ff_vcodec, pd->ff_opts);
     TC_UNLOCK_LIBAVCODEC;
 
     if (ret < 0) {
-        tc_log_error(MOD_NAME, "avcodec_open() failed");
+        tc_log_error(MOD_NAME, "avcodec_open2() failed");
         goto failed;
     }
     /* finally, pass up the extradata, if any */
