$NetBSD: patch-libavformat_nutdec.c,v 1.1 2013/05/17 21:50:34 jperkin Exp $

Avoid -Werror=return-type failure.

--- libavformat/nutdec.c.orig	2013-04-10 01:52:17.000000000 +0000
+++ libavformat/nutdec.c
@@ -849,7 +849,7 @@ av_log(s, AV_LOG_DEBUG, "read_timestamp(
     if     (stream_index == -1) return pts;
     else if(stream_index == -2) return back_ptr;
 
-assert(0);
+    return AV_NOPTS_VALUE;
 }
 
 static int read_seek(AVFormatContext *s, int stream_index, int64_t pts, int flags){
