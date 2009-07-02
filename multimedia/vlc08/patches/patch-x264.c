$NetBSD: patch-x264.c,v 1.2 2009/07/02 10:15:47 sborrill Exp $

Fix build with version of x264-devel currently in pkgsrc

--- modules/codec/x264.c.orig	2008-07-08 21:59:23.000000000 +0100
+++ modules/codec/x264.c	2009-07-02 10:49:13.000000000 +0100
@@ -29,6 +29,7 @@
 #include <vlc/sout.h>
 #include <vlc/decoder.h>
 
+#include <inttypes.h>
 #include <x264.h>
 
 #define SOUT_CFG_PREFIX "sout-x264-"
@@ -889,8 +890,10 @@
 #endif
 
 #if X264_BUILD >= 0x0013
+#if X264_BUILD < 65
     var_Get( p_enc, SOUT_CFG_PREFIX "b-adapt", &val );
     p_sys->param.b_bframe_adaptive = val.b_bool;
+#endif
 
     var_Get( p_enc, SOUT_CFG_PREFIX "b-bias", &val );
     if( val.i_int >= -100 && val.i_int <= 100 )
@@ -930,7 +933,7 @@
         p_sys->param.analyse.i_trellis = val.i_int;
 #endif
 
-#if X264_BUILD >= 41
+#if X264_BUILD >= 41 && X264_BUILD < 65
     var_Get( p_enc, SOUT_CFG_PREFIX "b-rdo", &val );
     p_sys->param.analyse.b_bframe_rdo = val.b_bool;
 #endif
@@ -940,7 +943,7 @@
     p_sys->param.analyse.b_fast_pskip = val.b_bool;
 #endif
 
-#if X264_BUILD >= 43
+#if X264_BUILD >= 43 && X264_BUILD < 65
     var_Get( p_enc, SOUT_CFG_PREFIX "bime", &val );
     p_sys->param.analyse.b_bidir_me = val.b_bool;
 #endif
@@ -965,10 +968,12 @@
     if( val.i_int >= 0 && val.i_int <= 32 )
         p_sys->param.analyse.i_luma_deadzone[1] = val.i_int;   
 
+#if X264_BUILD < 65
     var_Get( p_enc, SOUT_CFG_PREFIX "direct-8x8", &val );
     if( val.i_int >= -1 && val.i_int <= 1 )
         p_sys->param.analyse.i_direct_8x8_inference = val.i_int; 
 #endif
+#endif
 
     var_Get( p_enc, SOUT_CFG_PREFIX "asm", &val );
     if( !val.b_bool ) p_sys->param.cpu = 0;
