$NetBSD: patch-src-post-audio-stretch.c,v 1.1 2011/09/04 14:34:52 joerg Exp $

--- src/post/audio/stretch.c.orig	2011-08-30 13:13:24.000000000 +0000
+++ src/post/audio/stretch.c
@@ -200,9 +200,11 @@ typedef struct stretch_parameters_s {
  * description of params struct
  */
 START_PARAM_DESCR( stretch_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_BOOL, preserve_pitch, NULL, 0, 1, 0,
+PARAM_ITEM( stretch_parameters_t,
+	    POST_PARAM_TYPE_BOOL, preserve_pitch, NULL, 0, 1, 0,
             "Preserve pitch" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, factor, NULL, 0.5, 1.5, 0,
+PARAM_ITEM( stretch_parameters_t,
+	    POST_PARAM_TYPE_DOUBLE, factor, NULL, 0.5, 1.5, 0,
             "Time stretch factor (<1.0 shorten duration)" )
 END_PARAM_DESCR( param_descr )
 
