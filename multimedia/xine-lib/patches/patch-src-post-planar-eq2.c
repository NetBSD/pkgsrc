$NetBSD: patch-src-post-planar-eq2.c,v 1.5 2014/12/30 13:34:59 wiz Exp $

https://bugs.xine-project.org/show_bug.cgi?id=524

--- src/post/planar/eq2.c.orig	2012-02-05 19:17:02.000000000 +0000
+++ src/post/planar/eq2.c
@@ -288,19 +292,26 @@ typedef struct eq2_parameters_s {
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
 
