$NetBSD: patch-modules_videoio_src_cap__v4l.cpp,v 1.1 2016/03/01 20:14:24 joerg Exp $

--- modules/videoio/src/cap_v4l.cpp.orig	2015-12-18 15:02:16.000000000 +0000
+++ modules/videoio/src/cap_v4l.cpp
@@ -216,6 +216,7 @@ make & enjoy!
 #include <fcntl.h>
 #include <errno.h>
 #include <sys/ioctl.h>
+#include <inttypes.h>
 #include <sys/types.h>
 #include <sys/mman.h>
 
@@ -462,7 +463,9 @@ static int autosetup_capture_mode_v4l2(C
             V4L2_PIX_FMT_UYVY,
             V4L2_PIX_FMT_SN9C10X,
             V4L2_PIX_FMT_SBGGR8,
+#ifdef V4L2_PIX_FMT_SGBRG8
             V4L2_PIX_FMT_SGBRG8,
+#endif
             V4L2_PIX_FMT_RGB24
     };
 
@@ -515,9 +518,11 @@ static void v4l2_control_range(CvCapture
     case V4L2_CID_EXPOSURE:
         cap->exposure = range;
         break;
+#ifdef V4L2_CID_FOCUS_ABSOLUTE
     case V4L2_CID_FOCUS_ABSOLUTE:
         cap->focus = range;
         break;
+#endif
     }
 }
 
@@ -539,7 +544,9 @@ static void v4l2_scan_controls(CvCapture
         break;
   }
 
+#ifdef V4L2_CID_FOCUS_ABSOLUTE
   v4l2_control_range(capture, V4L2_CID_FOCUS_ABSOLUTE);
+#endif
 }
 
 static int v4l2_set_fps(CvCaptureCAM_V4L* capture) {
@@ -1523,12 +1530,14 @@ static IplImage* icvRetrieveFrameCAM_V4L
                 (unsigned char*)capture->frame.imageData);
         break;
 
+#ifdef V4L2_PIX_FMT_SGBRG8
     case V4L2_PIX_FMT_SGBRG8:
         sgbrg2rgb24(capture->form.fmt.pix.width,
                 capture->form.fmt.pix.height,
                 (unsigned char*)capture->buffers[(capture->bufferIndex+1) % capture->req.count].start,
                 (unsigned char*)capture->frame.imageData);
         break;
+#endif
     case V4L2_PIX_FMT_RGB24:
         rgb24_to_rgb24(capture->form.fmt.pix.width,
                 capture->form.fmt.pix.height,
@@ -1554,10 +1563,14 @@ static inline __u32 capPropertyToV4L2(in
         return V4L2_CID_GAIN;
     case CV_CAP_PROP_EXPOSURE:
         return V4L2_CID_EXPOSURE;
+#ifdef V4L2_CID_FOCUS_AUTO
     case CV_CAP_PROP_AUTOFOCUS:
         return V4L2_CID_FOCUS_AUTO;
+#endif
+#ifdef V4L2_CID_FOCUS_ABSOLUTE
     case CV_CAP_PROP_FOCUS:
         return V4L2_CID_FOCUS_ABSOLUTE;
+#endif
     default:
         return -1;
     }
