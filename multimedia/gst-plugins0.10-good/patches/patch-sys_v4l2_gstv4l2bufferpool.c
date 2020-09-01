$NetBSD: patch-sys_v4l2_gstv4l2bufferpool.c,v 1.1 2020/09/01 21:44:01 ryoon Exp $

v4l2_buffer.input has removed in recent kernel.

--- sys/v4l2/gstv4l2bufferpool.c.orig	2011-12-30 13:59:13.000000000 +0000
+++ sys/v4l2/gstv4l2bufferpool.c
@@ -181,7 +181,6 @@ gst_v4l2_buffer_new (GstV4l2BufferPool *
     GST_LOG_OBJECT (pool->v4l2elem, "  MMAP offset:  %u",
         ret->vbuffer.m.offset);
   GST_LOG_OBJECT (pool->v4l2elem, "  length:    %u", ret->vbuffer.length);
-  GST_LOG_OBJECT (pool->v4l2elem, "  input:     %u", ret->vbuffer.input);
 
   data = (guint8 *) v4l2_mmap (0, ret->vbuffer.length,
       PROT_READ | PROT_WRITE, MAP_SHARED, pool->video_fd,
