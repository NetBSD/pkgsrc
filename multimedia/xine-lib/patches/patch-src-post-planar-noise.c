$NetBSD: patch-src-post-planar-noise.c,v 1.7 2022/12/02 15:06:22 jperkin Exp $

https://bugs.xine-project.org/show_bug.cgi?id=524

--- src/post/planar/noise.c.orig	2019-12-13 20:47:50.000000000 +0000
+++ src/post/planar/noise.c
@@ -220,15 +220,20 @@ static const char *const enum_quality[] 
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
-PARAM_ITEM( POST_PARAM_TYPE_INT, quality, (char **)enum_quality, 0, 0, 0,
+PARAM_ITEM( noise_parameters_t,
+    POST_PARAM_TYPE_INT, quality, (char **)enum_quality, 0, 0, 0,
     "Quality level of noise" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, type, (char **)enum_types, 0, 0, 0,
+PARAM_ITEM( noise_parameters_t,
+    POST_PARAM_TYPE_INT, type, (char **)enum_types, 0, 0, 0,
     "Type of noise" )
-PARAM_ITEM( POST_PARAM_TYPE_BOOL, pattern, NULL, 0, 1, 0,
+PARAM_ITEM( noise_parameters_t,
+    POST_PARAM_TYPE_BOOL, pattern, NULL, 0, 1, 0,
     "Mix random noise with a (semi)regular pattern" )
 END_PARAM_DESCR( param_descr )
 
