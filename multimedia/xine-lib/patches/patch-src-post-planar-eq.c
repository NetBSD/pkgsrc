$NetBSD: patch-src-post-planar-eq.c,v 1.1 2011/09/04 14:34:52 joerg Exp $

--- src/post/planar/eq.c.orig	2011-08-30 13:13:46.000000000 +0000
+++ src/post/planar/eq.c
@@ -138,9 +138,11 @@ typedef struct eq_parameters_s {
  * description of params struct
  */
 START_PARAM_DESCR( eq_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_INT, brightness, NULL, -100, 100, 0,
+PARAM_ITEM( eq_parameters_t, 
+	    POST_PARAM_TYPE_INT, brightness, NULL, -100, 100, 0,
             "brightness" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, contrast, NULL, -100, 100, 0,
+PARAM_ITEM( eq_parameters_t, 
+	    POST_PARAM_TYPE_INT, contrast, NULL, -100, 100, 0,
             "contrast" )
 END_PARAM_DESCR( param_descr )
 
