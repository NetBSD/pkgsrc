$NetBSD: patch-sys_v4l2_gstv4l2object.c,v 1.2 2013/08/03 08:29:22 ryoon Exp $

* take care some video standard macros added by V4L2

--- sys/v4l2/gstv4l2object.c.orig	2013-04-26 09:30:32.000000000 +0000
+++ sys/v4l2/gstv4l2object.c
@@ -338,8 +338,12 @@ gst_v4l2_tv_norm_get_type (void)
       {V4L2_STD_NTSC, "NTSC", "NTSC"},
       {V4L2_STD_NTSC_M, "NTSC-M", "NTSC-M"},
       {V4L2_STD_NTSC_M_JP, "NTSC-M-JP", "NTSC-M-JP"},
+#ifdef V4L2_STD_NTSC_M_KR
       {V4L2_STD_NTSC_M_KR, "NTSC-M-KR", "NTSC-M-KR"},
+#endif
+#ifdef V4L2_STD_NTSC_443
       {V4L2_STD_NTSC_443, "NTSC-443", "NTSC-443"},
+#endif
 
       {V4L2_STD_PAL, "PAL", "PAL"},
       {V4L2_STD_PAL_BG, "PAL-BG", "PAL-BG"},
@@ -361,12 +365,16 @@ gst_v4l2_tv_norm_get_type (void)
       {V4L2_STD_SECAM_B, "SECAM-B", "SECAM-B"},
       {V4L2_STD_SECAM_G, "SECAM-G", "SECAM-G"},
       {V4L2_STD_SECAM_H, "SECAM-H", "SECAM-H"},
+#ifdef V4L2_STD_SECAM_DK
       {V4L2_STD_SECAM_DK, "SECAM-DK", "SECAM-DK"},
+#endif
       {V4L2_STD_SECAM_D, "SECAM-D", "SECAM-D"},
       {V4L2_STD_SECAM_K, "SECAM-K", "SECAM-K"},
       {V4L2_STD_SECAM_K1, "SECAM-K1", "SECAM-K1"},
       {V4L2_STD_SECAM_L, "SECAM-L", "SECAM-L"},
+#ifdef V4L2_STD_SECAM_LC
       {V4L2_STD_SECAM_LC, "SECAM-Lc", "SECAM-Lc"},
+#endif
 
       {0, NULL, NULL}
     };
@@ -1500,8 +1508,8 @@ gst_v4l2_object_get_caps_info (GstV4l2Ob
 #ifdef V4L2_PIX_FMT_PWC2
     } else if (g_str_equal (mimetype, "video/x-pwc2")) {
       fourcc = V4L2_PIX_FMT_PWC2;
-    }
 #endif
+    }
 
     if (dimensions) {
       const gchar *interlace_mode;
