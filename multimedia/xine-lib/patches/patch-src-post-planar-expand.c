$NetBSD: patch-src-post-planar-expand.c,v 1.1 2011/09/04 14:34:52 joerg Exp $

--- src/post/planar/expand.c.orig	2011-08-30 13:13:51.000000000 +0000
+++ src/post/planar/expand.c
@@ -73,13 +73,17 @@ typedef struct expand_parameters_s {
 } expand_parameters_t;
 
 START_PARAM_DESCR(expand_parameters_t)
-PARAM_ITEM(POST_PARAM_TYPE_BOOL, enable_automatic_shift, NULL, 0, 1, 0,
+PARAM_ITEM(expand_parameters_t,
+  POST_PARAM_TYPE_BOOL, enable_automatic_shift, NULL, 0, 1, 0,
   "enable automatic overlay shifting")
-PARAM_ITEM(POST_PARAM_TYPE_INT, overlay_y_offset, NULL, -500, 500, 0,
+PARAM_ITEM(expand_parameters_t,
+  POST_PARAM_TYPE_INT, overlay_y_offset, NULL, -500, 500, 0,
   "manually shift the overlay vertically")
-PARAM_ITEM(POST_PARAM_TYPE_DOUBLE, aspect, NULL, 1.0, 3.5, 0,
+PARAM_ITEM(expand_parameters_t,
+  POST_PARAM_TYPE_DOUBLE, aspect, NULL, 1.0, 3.5, 0,
   "target aspect ratio")
-PARAM_ITEM(POST_PARAM_TYPE_BOOL, centre_cut_out_mode, NULL, 0, 1, 0,
+PARAM_ITEM(expand_parameters_t,
+  POST_PARAM_TYPE_BOOL, centre_cut_out_mode, NULL, 0, 1, 0,
   "cut out centred 4:3 image contained in 16:9 frame")
 END_PARAM_DESCR(expand_param_descr)
 
