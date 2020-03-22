$NetBSD: patch-groove_file.c,v 1.1 2020/03/22 07:52:59 nia Exp $

Fix build with ffmpeg4.

--- groove/file.c.orig	2015-05-26 01:32:01.000000000 +0000
+++ groove/file.c
@@ -281,7 +281,7 @@ int groove_file_save(struct GrooveFile *
         ocodec->rc_buffer_size = icodec->rc_buffer_size;
         ocodec->field_order    = icodec->field_order;
 
-        uint64_t extra_size = (uint64_t)icodec->extradata_size + FF_INPUT_BUFFER_PADDING_SIZE;
+        uint64_t extra_size = (uint64_t)icodec->extradata_size + AV_INPUT_BUFFER_PADDING_SIZE;
         if (extra_size > INT_MAX) {
             cleanup_save(file);
             av_log(NULL, AV_LOG_ERROR, "codec extra size too big\n");
