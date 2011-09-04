$NetBSD: patch-src-post-planar-noise.c,v 1.1 2011/09/04 14:34:52 joerg Exp $

--- src/post/planar/noise.c.orig	2011-08-30 13:13:53.000000000 +0000
+++ src/post/planar/noise.c
@@ -329,15 +329,20 @@ static char *enum_quality[] = {"fixed", 
  * description of params struct
  */
 START_PARAM_DESCR( noise_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_INT, luma_strength, NULL, 0, 100, 0,
+PARAM_ITEM( noise_parameters_t, 
+    POST_PARAM_TYPE_INT, luma_strength, NULL, 0, 100, 0,
     "Amount of noise to add to luma channel" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, chroma_strength, NULL, 0, 100, 0,
+PARAM_ITEM( noise_parameters_t, 
+    POST_PARAM_TYPE_INT, chroma_strength, NULL, 0, 100, 0,
     "Amount of noise to add to chroma channel" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, quality, enum_quality, 0, 0, 0,
+PARAM_ITEM( noise_parameters_t, 
+    POST_PARAM_TYPE_INT, quality, enum_quality, 0, 0, 0,
     "Quality level of noise" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, type, enum_types, 0, 0, 0,
+PARAM_ITEM( noise_parameters_t, 
+    POST_PARAM_TYPE_INT, type, enum_types, 0, 0, 0,
     "Type of noise" )
-PARAM_ITEM( POST_PARAM_TYPE_BOOL, pattern, NULL, 0, 1, 0,
+PARAM_ITEM( noise_parameters_t, 
+    POST_PARAM_TYPE_BOOL, pattern, NULL, 0, 1, 0,
     "Mix random noise with a (semi)regular pattern" )
 END_PARAM_DESCR( param_descr )
 
