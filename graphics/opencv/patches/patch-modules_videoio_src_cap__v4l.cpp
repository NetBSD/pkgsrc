$NetBSD: patch-modules_videoio_src_cap__v4l.cpp,v 1.2 2017/03/16 21:59:13 prlw1 Exp $

Conditionalize settings not available in NetBSD's v4l2 emulation.

--- modules/videoio/src/cap_v4l.cpp.orig	2016-12-23 12:54:44.000000000 +0000
+++ modules/videoio/src/cap_v4l.cpp
@@ -216,6 +216,7 @@ make & enjoy!
 #include <fcntl.h>
 #include <errno.h>
 #include <sys/ioctl.h>
+#include <inttypes.h>
 #include <sys/types.h>
 #include <sys/mman.h>
 
@@ -469,9 +470,13 @@ static int autosetup_capture_mode_v4l2(C
             V4L2_PIX_FMT_UYVY,
             V4L2_PIX_FMT_SN9C10X,
             V4L2_PIX_FMT_SBGGR8,
+#ifdef V4L2_PIX_FMT_SGBRG8
             V4L2_PIX_FMT_SGBRG8,
-            V4L2_PIX_FMT_RGB24,
-            V4L2_PIX_FMT_Y16
+#endif
+            V4L2_PIX_FMT_RGB24
+#ifdef V4L2_PIX_FMT_Y16
+            ,V4L2_PIX_FMT_Y16
+#endif
     };
 
     for (size_t i = 0; i < sizeof(try_order) / sizeof(__u32); i++) {
@@ -520,12 +525,16 @@ static void v4l2_control_range(CvCapture
     case V4L2_CID_GAIN:
         cap->gain = range;
         break;
+#ifdef V4L2_CID_EXPOSURE_ABSOLUTE
     case V4L2_CID_EXPOSURE_ABSOLUTE:
         cap->exposure = range;
         break;
+#endif
+#ifdef V4L2_CID_FOCUS_ABSOLUTE
     case V4L2_CID_FOCUS_ABSOLUTE:
         cap->focus = range;
         break;
+#endif
     }
 }
 
@@ -547,7 +556,9 @@ static void v4l2_scan_controls(CvCapture
         break;
   }
 
+#ifdef V4L2_CID_FOCUS_ABSOLUTE
   v4l2_control_range(capture, V4L2_CID_FOCUS_ABSOLUTE);
+#endif
 }
 
 static int v4l2_set_fps(CvCaptureCAM_V4L* capture) {
@@ -563,8 +574,10 @@ static int v4l2_num_channels(__u32 palet
     case V4L2_PIX_FMT_YVU420:
     case V4L2_PIX_FMT_MJPEG:
     case V4L2_PIX_FMT_JPEG:
+#ifdef V4L2_PIX_FMT_Y16
     case V4L2_PIX_FMT_Y16:
         return 1;
+#endif
     case V4L2_PIX_FMT_YUYV:
     case V4L2_PIX_FMT_UYVY:
         return 2;
@@ -592,11 +605,13 @@ static void v4l2_create_frame(CvCaptureC
         case V4L2_PIX_FMT_YVU420:
             size.height = size.height * 3 / 2; // "1.5" channels
             break;
+#ifdef V4L2_PIX_FMT_Y16
         case V4L2_PIX_FMT_Y16:
             if(!capture->convert_rgb){
                 depth = IPL_DEPTH_16U;
             }
             break;
+#endif
         }
     }
 
@@ -1555,18 +1570,21 @@ static IplImage* icvRetrieveFrameCAM_V4L
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
                 (unsigned char*)capture->buffers[(capture->bufferIndex+1) % capture->req.count].start,
                 (unsigned char*)capture->frame.imageData);
         break;
+#ifdef V4L2_PIX_FMT_Y16
     case V4L2_PIX_FMT_Y16:
         if(capture->convert_rgb){
             y16_to_rgb24(capture->form.fmt.pix.width,
@@ -1579,6 +1597,7 @@ static IplImage* icvRetrieveFrameCAM_V4L
                    capture->frame.imageSize);
         }
         break;
+#endif
     }
 
     return(&capture->frame);
@@ -1596,14 +1615,22 @@ static inline __u32 capPropertyToV4L2(in
         return V4L2_CID_HUE;
     case CV_CAP_PROP_GAIN:
         return V4L2_CID_GAIN;
+#ifdef V4L2_CID_EXPOSURE_AUTO
     case CV_CAP_PROP_AUTO_EXPOSURE:
         return V4L2_CID_EXPOSURE_AUTO;
+#endif
+#ifdef V4L2_CID_EXPOSURE_ABSOLUTE
     case CV_CAP_PROP_EXPOSURE:
         return V4L2_CID_EXPOSURE_ABSOLUTE;
+#endif
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
@@ -1749,12 +1776,14 @@ static bool icvSetControl (CvCaptureCAM_
         return false;
     }
 
+#if defined(V4L2_CID_EXPOSURE_AUTO) && defined(V4L2_EXPOSURE_MANUAL) && defined(V4L2_CID_EXPOSURE_ABSOLUTE)
     if(control.id == V4L2_CID_EXPOSURE_AUTO && control.value == V4L2_EXPOSURE_MANUAL) {
         // update the control range for expose after disabling autoexposure
         // as it is not read correctly at startup
         // TODO check this again as it might be fixed with Linux 4.5
         v4l2_control_range(capture, V4L2_CID_EXPOSURE_ABSOLUTE);
     }
+#endif
 
     /* all was OK */
     return true;
