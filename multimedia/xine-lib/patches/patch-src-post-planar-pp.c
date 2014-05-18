$NetBSD: patch-src-post-planar-pp.c,v 1.2 2014/05/18 15:38:18 wiz Exp $

https://bugs.xine-project.org/show_bug.cgi?id=524

--- src/post/planar/pp.c.orig	2011-08-30 13:13:55.000000000 +0000
+++ src/post/planar/pp.c
@@ -56,9 +56,11 @@ typedef struct pp_parameters_s {
  * description of params struct
  */
 START_PARAM_DESCR( pp_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_INT, quality, NULL, 0, PP_QUALITY_MAX, 0,
+PARAM_ITEM( pp_parameters_t,
+	    POST_PARAM_TYPE_INT, quality, NULL, 0, PP_QUALITY_MAX, 0,
             "postprocessing quality" )
-PARAM_ITEM( POST_PARAM_TYPE_CHAR, mode, NULL, 0, 0, 0,
+PARAM_ITEM( pp_parameters_t,
+	    POST_PARAM_TYPE_CHAR, mode, NULL, 0, 0, 0,
             "mode string (overwrites all other options except quality)" )
 END_PARAM_DESCR( param_descr )
 
