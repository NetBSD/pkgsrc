$NetBSD: patch-export_ffmpeg_cfg.h,v 1.1 2015/11/21 17:14:26 adam Exp $

Fixes building against FFmpeg version >= 2.0.0 (gentoo patch).

--- export/ffmpeg_cfg.h.orig	2011-11-19 16:50:27.000000000 +0000
+++ export/ffmpeg_cfg.h
@@ -13,8 +13,6 @@ extern int lavc_param_vme;
 //extern int lavc_param_vqscale;
 //extern int lavc_param_vqmin;
 //extern int lavc_param_vqmax;
-extern int lavc_param_mb_qmin;
-extern int lavc_param_mb_qmax;
 extern int lavc_param_lmin;
 extern int lavc_param_lmax;
 extern int lavc_param_vqdiff;
