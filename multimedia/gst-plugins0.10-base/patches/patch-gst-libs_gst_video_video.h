$NetBSD: patch-gst-libs_gst_video_video.h,v 1.1 2013/02/26 11:03:21 joerg Exp $

--- gst-libs/gst/video/video.h.orig	2013-02-25 16:23:34.000000000 +0000
+++ gst-libs/gst/video/video.h
@@ -342,9 +342,9 @@ typedef enum {
  */
 #define GST_VIDEO_CAPS_RGB8_PALETTED \
   "video/x-raw-rgb, bpp = (int)8, depth = (int)8, "                     \
-      "width = "GST_VIDEO_SIZE_RANGE" , "		                \
+      "width = " GST_VIDEO_SIZE_RANGE " , "		                \
       "height = " GST_VIDEO_SIZE_RANGE ", "                             \
-      "framerate = "GST_VIDEO_FPS_RANGE
+      "framerate = " GST_VIDEO_FPS_RANGE
 
 /**
  * GST_VIDEO_CAPS_YUV:
