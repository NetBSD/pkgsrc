$NetBSD: patch-modules_videoio_src_cap__v4l.cpp,v 1.3 2017/09/04 15:23:49 fhajny Exp $

Conditionalize settings not available in NetBSD's v4l2 emulation.

--- modules/videoio/src/cap_v4l.cpp.orig	2017-08-03 23:58:23.000000000 +0000
+++ modules/videoio/src/cap_v4l.cpp
@@ -216,6 +216,7 @@ make & enjoy!
 #include <fcntl.h>
 #include <errno.h>
 #include <sys/ioctl.h>
+#include <inttypes.h>
 #include <sys/types.h>
 #include <sys/mman.h>
 
@@ -470,9 +471,13 @@ static int autosetup_capture_mode_v4l2(C
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
@@ -521,12 +526,16 @@ static void v4l2_control_range(CvCapture
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
 
@@ -548,7 +557,9 @@ static void v4l2_scan_controls(CvCapture
         break;
   }
 
+#ifdef V4L2_CID_FOCUS_ABSOLUTE
   v4l2_control_range(capture, V4L2_CID_FOCUS_ABSOLUTE);
+#endif
 }
 
 static int v4l2_set_fps(CvCaptureCAM_V4L* capture) {
@@ -564,8 +575,10 @@ static int v4l2_num_channels(__u32 palet
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
@@ -593,11 +606,13 @@ static void v4l2_create_frame(CvCaptureC
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
 
@@ -1558,18 +1573,21 @@ static IplImage* icvRetrieveFrameCAM_V4L
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
@@ -1582,6 +1600,7 @@ static IplImage* icvRetrieveFrameCAM_V4L
                    capture->frame.imageSize);
         }
         break;
+#endif
     }
 
     if (capture->returnFrame)
@@ -1602,14 +1621,22 @@ static inline __u32 capPropertyToV4L2(in
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
@@ -1755,12 +1782,14 @@ static bool icvSetControl (CvCaptureCAM_
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
