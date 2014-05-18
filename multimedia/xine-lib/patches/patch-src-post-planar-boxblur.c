$NetBSD: patch-src-post-planar-boxblur.c,v 1.2 2014/05/18 15:38:18 wiz Exp $

https://bugs.xine-project.org/show_bug.cgi?id=524

--- src/post/planar/boxblur.c.orig	2011-08-30 13:13:42.000000000 +0000
+++ src/post/planar/boxblur.c
@@ -51,13 +51,17 @@ typedef struct boxblur_parameters_s {
  * description of params struct
  */
 START_PARAM_DESCR( boxblur_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_INT, luma_radius, NULL, 0, 10, 0,
+PARAM_ITEM( boxblur_parameters_t,
+	    POST_PARAM_TYPE_INT, luma_radius, NULL, 0, 10, 0,
             "radius of luma blur" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, luma_power, NULL, 0, 10, 0,
+PARAM_ITEM( boxblur_parameters_t,
+	    POST_PARAM_TYPE_INT, luma_power, NULL, 0, 10, 0,
             "power of luma blur" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, chroma_radius, NULL, -1, 10, 0,
+PARAM_ITEM( boxblur_parameters_t,
+	    POST_PARAM_TYPE_INT, chroma_radius, NULL, -1, 10, 0,
             "radius of chroma blur (-1 = same as luma)" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, chroma_power, NULL, -1, 10, 0,
+PARAM_ITEM( boxblur_parameters_t,
+	    POST_PARAM_TYPE_INT, chroma_power, NULL, -1, 10, 0,
             "power of chroma blur (-1 = same as luma)" )
 END_PARAM_DESCR( param_descr )
 
