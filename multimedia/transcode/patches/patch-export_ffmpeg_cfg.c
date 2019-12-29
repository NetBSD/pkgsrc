$NetBSD: patch-export_ffmpeg_cfg.c,v 1.3 2019/12/29 10:23:53 markd Exp $

Fixes building against FFmpeg version >= 4.0.0 (gentoo patch).

--- export/ffmpeg_cfg.c.orig	2011-11-19 16:50:27.000000000 +0000
+++ export/ffmpeg_cfg.c
@@ -34,8 +34,6 @@ int lavc_param_vme = 4;
 //int lavc_param_vqscale = 0;
 //int lavc_param_vqmin = 2;
 //int lavc_param_vqmax = 31;
-int lavc_param_mb_qmin = 2;
-int lavc_param_mb_qmax = 31;
 int lavc_param_lmin = 2;
 int lavc_param_lmax = 31;
 int lavc_param_vqdiff = 3;
@@ -95,8 +93,8 @@ int lavc_param_last_pred= 0;
 int lavc_param_pre_me= 1;
 int lavc_param_me_subpel_quality= 8;
 int lavc_param_me_range=0;
-int lavc_param_ibias=FF_DEFAULT_QUANT_BIAS;
-int lavc_param_pbias=FF_DEFAULT_QUANT_BIAS;
+int lavc_param_ibias=0;
+int lavc_param_pbias=0;
 int lavc_param_coder=0;
 int lavc_param_context=0;
 char *lavc_param_intra_matrix = NULL;
@@ -126,7 +124,7 @@ int lavc_param_gmc = 0;
 //int lavc_param_atag = 0;
 //int lavc_param_abitrate = 224;
 
-char *lavc_param_video_preset = "medium";
+char *lavc_param_video_preset = "none";
 char *lavc_param_ffmpeg_datadir = "/usr/share/ffmpeg";
 
 TCConfigEntry lavcopts_conf[]={
@@ -138,20 +136,18 @@ TCConfigEntry lavcopts_conf[]={
     {"vratetol", &lavc_param_vrate_tolerance, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 4, 24000000},
     {"vhq", &lavc_param_mb_decision, TCCONF_TYPE_FLAG, 0, 0, 1},
     {"mbd", &lavc_param_mb_decision, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 9},
-    {"v4mv", &lavc_param_v4mv, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_4MV},
+    {"v4mv", &lavc_param_v4mv, TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_4MV},
     {"vme", &lavc_param_vme, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 5},
 //    {"vqscale", &lavc_param_vqscale, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 31},
 //    {"vqmin", &lavc_param_vqmin, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 31},
 //    {"vqmax", &lavc_param_vqmax, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 31},
-    {"mbqmin", &lavc_param_mb_qmin, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 31},
-    {"mbqmax", &lavc_param_mb_qmax, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 31},
     {"lmin", &lavc_param_lmin, TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.01, 255.0},
     {"lmax", &lavc_param_lmax, TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.01, 255.0},
     {"vqdiff", &lavc_param_vqdiff, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 31},
     {"vqcomp", &lavc_param_vqcompress, TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.0, 1.0},
     {"vqblur", &lavc_param_vqblur, TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.0, 1.0},
     {"vb_qfactor", &lavc_param_vb_qfactor, TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, -31.0, 31.0},
-    {"vmax_b_frames", &lavc_param_vmax_b_frames, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, FF_MAX_B_FRAMES},
+    {"vmax_b_frames", &lavc_param_vmax_b_frames, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, INT_MAX},
 //    {"vpass", &lavc_param_vpass, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 2},
     {"vrc_strategy", &lavc_param_vrc_strategy, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 2},
     {"vb_strategy", &lavc_param_vb_strategy, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 10},
@@ -160,9 +156,9 @@ TCConfigEntry lavcopts_conf[]={
     {"vcelim", &lavc_param_chroma_elim_threshold, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -99, 99},
     {"vpsize", &lavc_param_packet_size, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 100000000},
     {"vstrict", &lavc_param_strict, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -99, 99},
-    {"vdpart", &lavc_param_data_partitioning, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_PART},
+    {"vdpart", &lavc_param_data_partitioning, TCCONF_TYPE_FLAG, 0, 0, 1},
 //    {"keyint", &lavc_param_keyint, TCCONF_TYPE_INT, 0, 0, 0},
-    {"gray", &lavc_param_gray, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_PART},
+    {"gray", &lavc_param_gray, TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_GRAY},
     {"mpeg_quant", &lavc_param_mpeg_quant, TCCONF_TYPE_FLAG, 0, 0, 1},
     {"vi_qfactor", &lavc_param_vi_qfactor, TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, -31.0, 31.0},
     {"vi_qoffset", &lavc_param_vi_qoffset, TCCONF_TYPE_FLOAT, TCCONF_FLAG_RANGE, 0.0, 31.0},
@@ -188,7 +184,7 @@ TCConfigEntry lavcopts_conf[]={
     {"pred", &lavc_param_prediction_method, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 20},
     {"format", &lavc_param_format, TCCONF_TYPE_STRING, 0, 0, 0},
     {"debug", &lavc_param_debug, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 100000000},
-    {"psnr", &lavc_param_psnr, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_PSNR},
+    {"psnr", &lavc_param_psnr, TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_PSNR},
     {"precmp", &lavc_param_me_pre_cmp, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 2000},
     {"cmp", &lavc_param_me_cmp, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 2000},
     {"subcmp", &lavc_param_me_sub_cmp, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 2000},
@@ -196,9 +192,9 @@ TCConfigEntry lavcopts_conf[]={
     {"ildctcmp", &lavc_param_ildct_cmp, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 2000},
     {"predia", &lavc_param_pre_dia_size, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -2000, 2000},
     {"dia", &lavc_param_dia_size, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -2000, 2000},
-    {"qpel", &lavc_param_qpel, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_QPEL},
+    {"qpel", &lavc_param_qpel, TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_QPEL},
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)   
-    {"trell", &lavc_param_trell, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_TRELLIS_QUANT},
+    {"trell", &lavc_param_trell, TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_TRELLIS_QUANT},
 #else
     {"trell", &lavc_param_trell, TCCONF_TYPE_FLAG, 0, 0, 1},
 #endif
@@ -207,32 +203,32 @@ TCConfigEntry lavcopts_conf[]={
     {"subq", &lavc_param_me_subpel_quality, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 8},
     {"me_range", &lavc_param_me_range, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 16000},
 #if LIBAVCODEC_VERSION_INT < ((52<<16)+(0<<8)+0)   
-    {"aic", &lavc_param_aic, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_H263P_AIC},
+    {"aic", &lavc_param_aic, TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_H263P_AIC},
 #else
-    {"aic", &lavc_param_aic, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_AC_PRED},
+    {"aic", &lavc_param_aic, TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_AC_PRED},
 #endif    
-    {"umv", &lavc_param_umv, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_H263P_UMV},
+    {"umv", &lavc_param_umv, TCCONF_TYPE_FLAG, 0, 0, 1},
     {"ibias", &lavc_param_ibias, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -512, 512},
     {"pbias", &lavc_param_pbias, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -512, 512},
     {"coder", &lavc_param_coder, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 10},
     {"context", &lavc_param_context, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 10},
     {"intra_matrix", &lavc_param_intra_matrix, TCCONF_TYPE_STRING, 0, 0, 0},
     {"inter_matrix", &lavc_param_inter_matrix, TCCONF_TYPE_STRING, 0, 0, 0},
-    {"cbp", &lavc_param_cbp, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_CBP_RD},
-    {"mv0", &lavc_param_mv0, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_MV0},
+    {"cbp", &lavc_param_cbp, TCCONF_TYPE_FLAG, 0, 0, 1},
+    {"mv0", &lavc_param_mv0, TCCONF_TYPE_FLAG, 0, 0, 1},
     {"nr", &lavc_param_noise_reduction, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 1000000},
-    {"qprd", &lavc_param_qp_rd, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_QP_RD},
+    {"qprd", &lavc_param_qp_rd, TCCONF_TYPE_FLAG, 0, 0, 1},
     {"threads", &lavc_param_threads, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 1, 16},
-    {"ss", &lavc_param_ss, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_H263P_SLICE_STRUCT},
-    {"svcd_sof", &lavc_param_scan_offset, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_SVCD_SCAN_OFFSET},
-    {"alt", &lavc_param_alt, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_ALT_SCAN},
-    {"ilme", &lavc_param_ilme, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_INTERLACED_ME},
+    {"ss", &lavc_param_ss, TCCONF_TYPE_FLAG, 0, 0, 1},
+    {"svcd_sof", &lavc_param_scan_offset, TCCONF_TYPE_FLAG, 0, 0, 1},
+    {"alt", &lavc_param_alt, TCCONF_TYPE_FLAG, 0, 0, 1},
+    {"ilme", &lavc_param_ilme, TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_INTERLACED_ME},
     {"inter_threshold", &lavc_param_inter_threshold, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -1000000, 1000000},
     {"sc_threshold", &lavc_param_sc_threshold, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -1000000, 1000000},
     {"top", &lavc_param_top, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, -1, 1},
-    {"gmc", &lavc_param_gmc, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_GMC},
-    {"trunc", &lavc_param_trunc, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_TRUNCATED},
-    {"closedgop", &lavc_param_closedgop, TCCONF_TYPE_FLAG, 0, 0, CODEC_FLAG_CLOSED_GOP},
+    {"gmc", &lavc_param_gmc, TCCONF_TYPE_FLAG, 0, 0, 1},
+    {"trunc", &lavc_param_trunc, TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_TRUNCATED},
+    {"closedgop", &lavc_param_closedgop, TCCONF_TYPE_FLAG, 0, 0, AV_CODEC_FLAG_CLOSED_GOP},
     {"intra_dc_precision", &lavc_param_intra_dc_precision, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 16},
     {"skip_top", &lavc_param_skip_top, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 1000},
     {"skip_bottom", &lavc_param_skip_bottom, TCCONF_TYPE_INT, TCCONF_FLAG_RANGE, 0, 1000},
