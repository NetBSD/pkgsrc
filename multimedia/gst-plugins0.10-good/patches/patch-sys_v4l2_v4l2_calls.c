$NetBSD: patch-sys_v4l2_v4l2_calls.c,v 1.1 2016/07/16 04:35:13 markd Exp $

Fix building with linux-headers >= 3.9

--- sys/v4l2/v4l2_calls.c.orig	2014-06-23 03:18:47.384343480 +0000
+++ sys/v4l2/v4l2_calls.c
@@ -294,8 +294,12 @@ gst_v4l2_fill_lists (GstV4l2Object * v4l
         break;
       case V4L2_CID_HFLIP:
       case V4L2_CID_VFLIP:
+#ifndef V4L2_CID_PAN_RESET
       case V4L2_CID_HCENTER:
+#endif
+#ifndef V4L2_CID_TILT_RESET
       case V4L2_CID_VCENTER:
+#endif
 #ifdef V4L2_CID_PAN_RESET
       case V4L2_CID_PAN_RESET:
 #endif
