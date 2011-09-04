$NetBSD: patch-src-post-planar-denoise3d.c,v 1.1 2011/09/04 14:34:52 joerg Exp $

--- src/post/planar/denoise3d.c.orig	2011-08-30 13:13:44.000000000 +0000
+++ src/post/planar/denoise3d.c
@@ -58,11 +58,14 @@ typedef struct denoise3d_parameters_s {
  * description of params struct
  */
 START_PARAM_DESCR( denoise3d_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, luma, NULL, 0, 10, 0,
+PARAM_ITEM( denoise3d_parameters_t,
+	    POST_PARAM_TYPE_DOUBLE, luma, NULL, 0, 10, 0,
             "spatial luma strength" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, chroma, NULL, 0, 10, 0,
+PARAM_ITEM( denoise3d_parameters_t,
+	    POST_PARAM_TYPE_DOUBLE, chroma, NULL, 0, 10, 0,
             "spatial chroma strength" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, time, NULL, 0, 10, 0,
+PARAM_ITEM( denoise3d_parameters_t,
+	    POST_PARAM_TYPE_DOUBLE, time, NULL, 0, 10, 0,
             "temporal strength" )
 END_PARAM_DESCR( param_descr )
 
