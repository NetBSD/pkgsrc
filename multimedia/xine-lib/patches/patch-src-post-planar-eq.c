$NetBSD: patch-src-post-planar-eq.c,v 1.6 2022/12/02 15:06:22 jperkin Exp $

https://bugs.xine-project.org/show_bug.cgi?id=524

--- src/post/planar/eq.c.orig	2019-12-13 20:47:50.000000000 +0000
+++ src/post/planar/eq.c
@@ -155,9 +155,11 @@ typedef struct eq_parameters_s {
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
 
