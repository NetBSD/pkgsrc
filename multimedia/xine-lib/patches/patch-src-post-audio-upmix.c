$NetBSD: patch-src-post-audio-upmix.c,v 1.2 2014/05/18 15:38:18 wiz Exp $

https://bugs.xine-project.org/show_bug.cgi?id=524

--- src/post/audio/upmix.c.orig	2011-08-30 13:13:28.000000000 +0000
+++ src/post/audio/upmix.c
@@ -89,7 +89,8 @@ typedef struct upmix_parameters_s {
  * description of params struct
  */
 START_PARAM_DESCR( upmix_parameters_t )
-PARAM_ITEM( POST_PARAM_TYPE_INT, cut_off_freq, NULL, 0, 500, 0,
+PARAM_ITEM( upmix_parameters_t,
+	    POST_PARAM_TYPE_INT, cut_off_freq, NULL, 0, 500, 0,
             "cut_off_freq" )
 END_PARAM_DESCR( param_descr )
 
