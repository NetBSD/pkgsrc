$NetBSD: patch-src-post-planar-unsharp.c,v 1.1 2011/09/04 14:34:52 joerg Exp $

--- src/post/planar/unsharp.c.orig	2011-08-30 13:13:58.000000000 +0000
+++ src/post/planar/unsharp.c
@@ -141,17 +141,23 @@ typedef struct unsharp_parameters_s {
  * description of params struct
  */
 START_PARAM_DESCR( unsharp_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_INT, luma_matrix_width, NULL, 3, 11, 0,
+PARAM_ITEM( unsharp_parameters_t,
+	    POST_PARAM_TYPE_INT, luma_matrix_width, NULL, 3, 11, 0,
             "width of the matrix (must be odd)" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, luma_matrix_height, NULL, 3, 11, 0,
+PARAM_ITEM( unsharp_parameters_t,
+	    POST_PARAM_TYPE_INT, luma_matrix_height, NULL, 3, 11, 0,
             "height of the matrix (must be odd)" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, luma_amount, NULL, -2, 2, 0,
+PARAM_ITEM( unsharp_parameters_t,
+	    POST_PARAM_TYPE_DOUBLE, luma_amount, NULL, -2, 2, 0,
             "relative amount of sharpness/blur (=0 disable, <0 blur, >0 sharpen)" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, chroma_matrix_width, NULL, 3, 11, 0,
+PARAM_ITEM( unsharp_parameters_t,
+	    POST_PARAM_TYPE_INT, chroma_matrix_width, NULL, 3, 11, 0,
             "width of the matrix (must be odd)" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, chroma_matrix_height, NULL, 3, 11, 0,
+PARAM_ITEM( unsharp_parameters_t,
+	    POST_PARAM_TYPE_INT, chroma_matrix_height, NULL, 3, 11, 0,
             "height of the matrix (must be odd)" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, chroma_amount, NULL, -2, 2, 0,
+PARAM_ITEM( unsharp_parameters_t,
+	    POST_PARAM_TYPE_DOUBLE, chroma_amount, NULL, -2, 2, 0,
             "relative amount of sharpness/blur (=0 disable, <0 blur, >0 sharpen)" )
 END_PARAM_DESCR( param_descr )
 
