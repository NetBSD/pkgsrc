$NetBSD: patch-modules_codec_x264.c,v 1.1 2018/06/16 09:49:00 markd Exp $

Build with recent X264.
http://mail-index.netbsd.org/pkgsrc-users/2018/04/07/msg026468.html

--- modules/codec/x264.c.orig	2015-04-13 19:54:35.000000000 +0000
+++ modules/codec/x264.c
@@ -845,18 +845,13 @@ static int  Open ( vlc_object_t *p_this 
     p_sys->i_colorspace = X264_CSP_I420;
 #if X264_BUILD >= 118
     char *psz_profile = var_GetString( p_enc, SOUT_CFG_PREFIX "profile" );
-    if( psz_profile )
-    {
-        const int mask = x264_bit_depth > 8 ? X264_CSP_HIGH_DEPTH : 0;
-
-
 # ifdef MODULE_NAME_IS_x26410b
-        if( mask == 0)
-        {
-            msg_Err( p_enc, "Only high bith depth encoding supported, bit depth:%d", x264_bit_depth);
-            return VLC_EGENERIC;
-        }
+    const int mask = X264_CSP_HIGH_DEPTH;
+# else
+    const int mask = 0;
 # endif
+    if( psz_profile )
+    {
 
         if( !strcmp( psz_profile, "high10" ) )
         {
@@ -913,6 +908,10 @@ static int  Open ( vlc_object_t *p_this 
 #else
     x264_param_default( &p_sys->param );
     x264_param_default_preset( &p_sys->param, psz_preset, psz_tune );
+# if X264_BUILD > 152
+    if( mask )
+        p_sys->param.i_bitdepth = 10;
+# endif
 #endif
     free( psz_preset );
     free( psz_tune );
