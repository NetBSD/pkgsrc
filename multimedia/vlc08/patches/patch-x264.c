$NetBSD: patch-x264.c,v 1.1.2.2 2009/01/30 17:24:33 tron Exp $

Fix build with version of x264-devel currently in pkgsrc

--- modules/codec/x264.c.orig	2009-01-28 11:57:28.000000000 +0000
+++ modules/codec/x264.c	2009-01-28 12:06:20.000000000 +0000
@@ -889,8 +889,10 @@
 #endif
 
 #if X264_BUILD >= 0x0013
+#if X264_BUILD < 65
     var_Get( p_enc, SOUT_CFG_PREFIX "b-adapt", &val );
     p_sys->param.b_bframe_adaptive = val.b_bool;
+#endif
 
     var_Get( p_enc, SOUT_CFG_PREFIX "b-bias", &val );
     if( val.i_int >= -100 && val.i_int <= 100 )
@@ -930,7 +932,7 @@
         p_sys->param.analyse.i_trellis = val.i_int;
 #endif
 
-#if X264_BUILD >= 41
+#if X264_BUILD >= 41 && X264_BUILD < 65
     var_Get( p_enc, SOUT_CFG_PREFIX "b-rdo", &val );
     p_sys->param.analyse.b_bframe_rdo = val.b_bool;
 #endif
@@ -940,7 +942,7 @@
     p_sys->param.analyse.b_fast_pskip = val.b_bool;
 #endif
 
-#if X264_BUILD >= 43
+#if X264_BUILD >= 43 && X264_BUILD < 65
     var_Get( p_enc, SOUT_CFG_PREFIX "bime", &val );
     p_sys->param.analyse.b_bidir_me = val.b_bool;
 #endif
