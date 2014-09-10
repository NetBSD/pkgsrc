$NetBSD: patch-src_mad-decoder.c,v 1.1 2014/09/10 12:09:42 joerg Exp $

--- src/mad-decoder.c.orig	2014-09-09 18:36:33.000000000 +0000
+++ src/mad-decoder.c
@@ -404,7 +404,7 @@ enum mad_flow input(void *data, struct m
     gint len;
 
     if(remain){
-        g_memmove(info->buf,stream->this_frame,remain);
+        memmove(info->buf,stream->this_frame,remain);
     }
     
     pthread_mutex_lock(&(info->mutex));
