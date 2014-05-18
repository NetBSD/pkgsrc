$NetBSD: patch-src-post-audio-upmix_mono.c,v 1.2 2014/05/18 15:38:18 wiz Exp $

https://bugs.xine-project.org/show_bug.cgi?id=524

--- src/post/audio/upmix_mono.c.orig	2011-08-30 13:13:31.000000000 +0000
+++ src/post/audio/upmix_mono.c
@@ -48,7 +48,8 @@ typedef struct upmix_mono_parameters_s {
  * description of params struct
  */
 START_PARAM_DESCR( upmix_mono_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_INT, channel, NULL, -1, 5, 0,
+PARAM_ITEM( upmix_mono_parameters_t,
+	    POST_PARAM_TYPE_INT, channel, NULL, -1, 5, 0,
             "Select channel to upmix (duplicate) to stereo" )
 END_PARAM_DESCR( param_descr )
 
