$NetBSD: patch-src-post-planar-eq2.c,v 1.1 2011/09/04 14:34:52 joerg Exp $

--- src/post/planar/eq2.c.orig	2011-08-30 13:13:49.000000000 +0000
+++ src/post/planar/eq2.c
@@ -288,19 +288,26 @@ typedef struct eq2_parameters_s {
  * description of params struct
  */
 START_PARAM_DESCR( eq2_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, gamma, NULL, 0, 5, 0,
+PARAM_ITEM( eq2_parameters_t, 
+	    POST_PARAM_TYPE_DOUBLE, gamma, NULL, 0, 5, 0,
             "gamma" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, brightness, NULL, -1, 1, 0,
+PARAM_ITEM( eq2_parameters_t, 
+	    POST_PARAM_TYPE_DOUBLE, brightness, NULL, -1, 1, 0,
             "brightness" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, contrast, NULL, 0, 2, 0,
+PARAM_ITEM( eq2_parameters_t, 
+	    POST_PARAM_TYPE_DOUBLE, contrast, NULL, 0, 2, 0,
             "contrast" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, saturation, NULL, 0, 2, 0,
+PARAM_ITEM( eq2_parameters_t, 
+	    POST_PARAM_TYPE_DOUBLE, saturation, NULL, 0, 2, 0,
             "saturation" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, rgamma, NULL, 0, 5, 0,
+PARAM_ITEM( eq2_parameters_t, 
+	    POST_PARAM_TYPE_DOUBLE, rgamma, NULL, 0, 5, 0,
             "rgamma" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, ggamma, NULL, 0, 5, 0,
+PARAM_ITEM( eq2_parameters_t, 
+	    POST_PARAM_TYPE_DOUBLE, ggamma, NULL, 0, 5, 0,
             "ggamma" )
-PARAM_ITEM( POST_PARAM_TYPE_DOUBLE, bgamma, NULL, 0, 5, 0,
+PARAM_ITEM( eq2_parameters_t, 
+	    POST_PARAM_TYPE_DOUBLE, bgamma, NULL, 0, 5, 0,
             "bgamma" )
 END_PARAM_DESCR( param_descr )
 
