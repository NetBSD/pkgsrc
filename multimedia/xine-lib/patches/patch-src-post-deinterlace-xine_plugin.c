$NetBSD: patch-src-post-deinterlace-xine_plugin.c,v 1.3 2018/11/13 11:10:41 markd Exp $

https://bugs.xine-project.org/show_bug.cgi?id=524

--- src/post/deinterlace/xine_plugin.c.orig	2018-01-11 12:49:47.000000000 +0000
+++ src/post/deinterlace/xine_plugin.c
@@ -86,23 +86,32 @@ typedef struct deinterlace_parameters_s
  * description of params struct
  */
 START_PARAM_DESCR( deinterlace_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_INT, method, (char **)enum_methods, 0, 0, 0,
+PARAM_ITEM( deinterlace_parameters_t,
+            POST_PARAM_TYPE_INT, method, (char **)enum_methods, 0, 0, 0,
             "deinterlace method" )
-PARAM_ITEM( POST_PARAM_TYPE_BOOL, enabled, NULL, 0, 1, 0,
+PARAM_ITEM( deinterlace_parameters_t,
+            POST_PARAM_TYPE_BOOL, enabled, NULL, 0, 1, 0,
             "enable/disable" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, pulldown, (char **)enum_pulldown, 0, 0, 0,
+PARAM_ITEM( deinterlace_parameters_t,
+            POST_PARAM_TYPE_INT, pulldown, (char **)enum_pulldown, 0, 0, 0,
             "pulldown algorithm" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, pulldown_error_wait, NULL, 0, 0, 0,
+PARAM_ITEM( deinterlace_parameters_t,
+            POST_PARAM_TYPE_INT, pulldown_error_wait, NULL, 0, 0, 0,
             "number of frames of telecine pattern sync required before mode change" )
-PARAM_ITEM( POST_PARAM_TYPE_INT, framerate_mode, (char **)enum_framerate, 0, 0, 0,
+PARAM_ITEM( deinterlace_parameters_t,
+            POST_PARAM_TYPE_INT, framerate_mode, (char **)enum_framerate, 0, 0, 0,
             "framerate output mode" )
-PARAM_ITEM( POST_PARAM_TYPE_BOOL, judder_correction, NULL, 0, 1, 0,
+PARAM_ITEM( deinterlace_parameters_t,
+            POST_PARAM_TYPE_BOOL, judder_correction, NULL, 0, 1, 0,
             "make frames evenly spaced for film mode (24 fps)" )
-PARAM_ITEM( POST_PARAM_TYPE_BOOL, use_progressive_frame_flag, NULL, 0, 1, 0,
+PARAM_ITEM( deinterlace_parameters_t,
+            POST_PARAM_TYPE_BOOL, use_progressive_frame_flag, NULL, 0, 1, 0,
             "disable deinterlacing when progressive_frame flag is set" )
-PARAM_ITEM( POST_PARAM_TYPE_BOOL, chroma_filter, NULL, 0, 1, 0,
+PARAM_ITEM( deinterlace_parameters_t,
+            POST_PARAM_TYPE_BOOL, chroma_filter, NULL, 0, 1, 0,
             "apply chroma filter after deinterlacing" )
-PARAM_ITEM( POST_PARAM_TYPE_BOOL, cheap_mode, NULL, 0, 1, 0,
+PARAM_ITEM( deinterlace_parameters_t,
+            POST_PARAM_TYPE_BOOL, cheap_mode, NULL, 0, 1, 0,
             "skip image format conversion - cheaper but not 100% correct" )
 END_PARAM_DESCR( param_descr )
 
