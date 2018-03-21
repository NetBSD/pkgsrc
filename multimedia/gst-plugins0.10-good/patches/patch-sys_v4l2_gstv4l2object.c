$NetBSD: patch-sys_v4l2_gstv4l2object.c,v 1.2 2018/03/21 18:00:51 kamil Exp $

* take care some video standard macros added by V4L2 in Linux 2.6.17
  (not in NetBSD)
* don't use V4L2_FRMIVAL_TYPE_CONTINUOUS uncontionally (needed on NetBSD)

--- sys/v4l2/gstv4l2object.c.orig	2011-12-30 13:59:13.000000000 +0000
+++ sys/v4l2/gstv4l2object.c
@@ -331,8 +331,12 @@ gst_v4l2_tv_norm_get_type (void)
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
@@ -354,12 +358,16 @@ gst_v4l2_tv_norm_get_type (void)
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
@@ -1546,7 +1554,7 @@ gst_v4l2_object_get_nearest_size (GstV4l
 
 
 /* The frame interval enumeration code first appeared in Linux 2.6.19. */
-#ifdef VIDIOC_ENUM_FRAMEINTERVALS
+#if defined(VIDIOC_ENUM_FRAMEINTERVALS) && defined(V4L2_FRMIVAL_TYPE_CONTINUOUS)
 static GstStructure *
 gst_v4l2_object_probe_caps_for_format_and_size (GstV4l2Object * v4l2object,
     guint32 pixelformat,
@@ -1754,7 +1762,7 @@ unknown_type:
     return NULL;
   }
 }
-#endif /* defined VIDIOC_ENUM_FRAMEINTERVALS */
+#endif /* defined VIDIOC_ENUM_FRAMEINTERVALS && defined V4L2_FRMIVAL_TYPE_CONTINUOUS */
 
 #ifdef VIDIOC_ENUM_FRAMESIZES
 static gint
