$NetBSD: patch-modules_videoio_src_cap__v4l.cpp,v 1.6 2019/12/16 08:24:39 adam Exp $

Conditionalize settings not available in NetBSD's v4l2 emulation.

--- modules/videoio/src/cap_v4l.cpp.orig	2019-10-09 11:42:29.000000000 +0000
+++ modules/videoio/src/cap_v4l.cpp
@@ -218,6 +218,7 @@ make & enjoy!
 #include <fcntl.h>
 #include <errno.h>
 #include <sys/ioctl.h>
+#include <inttypes.h>
 #include <sys/types.h>
 #include <sys/mman.h>
 
@@ -239,24 +240,30 @@ make & enjoy!
 #endif
 
 // https://github.com/opencv/opencv/issues/13335
+#ifdef V4L2_CID_CAMERA_CLASS_BASE
 #ifndef V4L2_CID_ISO_SENSITIVITY
 #define V4L2_CID_ISO_SENSITIVITY (V4L2_CID_CAMERA_CLASS_BASE+23)
 #endif
+#endif
 
 // https://github.com/opencv/opencv/issues/13929
+#ifdef V4L2_CID_MPEG_BASE
 #ifndef V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_HEIGHT
 #define V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_HEIGHT (V4L2_CID_MPEG_BASE+364)
 #endif
 #ifndef V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_WIDTH
 #define V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_WIDTH (V4L2_CID_MPEG_BASE+365)
 #endif
+#endif
 
 #ifndef V4L2_CID_ROTATE
 #define V4L2_CID_ROTATE (V4L2_CID_BASE+34)
 #endif
+#ifdef V4L2_CID_CAMERA_CLASS_BASE
 #ifndef V4L2_CID_IRIS_ABSOLUTE
 #define V4L2_CID_IRIS_ABSOLUTE (V4L2_CID_CAMERA_CLASS_BASE+17)
 #endif
+#endif
 
 #ifndef V4L2_PIX_FMT_Y10
 #define V4L2_PIX_FMT_Y10 v4l2_fourcc('Y', '1', '0', ' ')
@@ -493,13 +500,17 @@ bool CvCaptureCAM_V4L::autosetup_capture
             V4L2_PIX_FMT_NV12,
             V4L2_PIX_FMT_NV21,
             V4L2_PIX_FMT_SBGGR8,
+#ifdef V4L2_PIX_FMT_SGBRG8
             V4L2_PIX_FMT_SGBRG8,
+#endif
             V4L2_PIX_FMT_SN9C10X,
 #ifdef HAVE_JPEG
             V4L2_PIX_FMT_MJPEG,
             V4L2_PIX_FMT_JPEG,
 #endif
+#ifdef V4L2_PIX_FMT_Y16
             V4L2_PIX_FMT_Y16,
+#endif
             V4L2_PIX_FMT_Y10,
             V4L2_PIX_FMT_GREY,
     };
@@ -545,9 +556,13 @@ bool CvCaptureCAM_V4L::convertableToRgb(
     case V4L2_PIX_FMT_UYVY:
     case V4L2_PIX_FMT_SBGGR8:
     case V4L2_PIX_FMT_SN9C10X:
+#ifdef V4L2_PIX_FMT_SGBRG8
     case V4L2_PIX_FMT_SGBRG8:
+#endif
     case V4L2_PIX_FMT_RGB24:
+#ifdef V4L2_PIX_FMT_Y16
     case V4L2_PIX_FMT_Y16:
+#endif
     case V4L2_PIX_FMT_Y10:
     case V4L2_PIX_FMT_GREY:
     case V4L2_PIX_FMT_BGR24:
@@ -582,7 +597,9 @@ void CvCaptureCAM_V4L::v4l2_create_frame
             channels = 1;
             size.height = size.height * 3 / 2; // "1.5" channels
             break;
+#ifdef V4L2_PIX_FMT_Y16
         case V4L2_PIX_FMT_Y16:
+#endif
         case V4L2_PIX_FMT_Y10:
             depth = IPL_DEPTH_16U;
             /* fallthru */
@@ -1408,11 +1425,13 @@ void CvCaptureCAM_V4L::convertToRgb(cons
                 (unsigned char*)buffers[MAX_V4L_BUFFERS].start,
                 (unsigned char*)frame.imageData);
         return;
+#ifdef V4L2_PIX_FMT_SGBRG8
     case V4L2_PIX_FMT_SGBRG8:
         sgbrg2rgb24(imageSize.width, imageSize.height,
                 (unsigned char*)currentBuffer.start,
                 (unsigned char*)frame.imageData);
         return;
+#endif
     default:
         break;
     }
@@ -1450,6 +1469,7 @@ void CvCaptureCAM_V4L::convertToRgb(cons
     case V4L2_PIX_FMT_RGB24:
         cv::cvtColor(cv::Mat(imageSize, CV_8UC3, currentBuffer.start), destination, COLOR_RGB2BGR);
         return;
+#ifdef V4L2_PIX_FMT_Y16
     case V4L2_PIX_FMT_Y16:
     {
         cv::Mat temp(imageSize, CV_8UC1, buffers[MAX_V4L_BUFFERS].start);
@@ -1464,6 +1484,7 @@ void CvCaptureCAM_V4L::convertToRgb(cons
         cv::cvtColor(temp, destination, COLOR_GRAY2BGR);
         return;
     }
+#endif
     case V4L2_PIX_FMT_GREY:
         cv::cvtColor(cv::Mat(imageSize, CV_8UC1, currentBuffer.start), destination, COLOR_GRAY2BGR);
         break;
@@ -1576,8 +1597,10 @@ static inline int capPropertyToV4L2(int 
         return -1;
     case cv::CAP_PROP_FOURCC:
         return -1;
+#ifdef V4L2_CID_MPEG_VIDEO_B_FRAMES
     case cv::CAP_PROP_FRAME_COUNT:
         return V4L2_CID_MPEG_VIDEO_B_FRAMES;
+#endif
     case cv::CAP_PROP_FORMAT:
         return -1;
     case cv::CAP_PROP_MODE:
@@ -1592,8 +1615,10 @@ static inline int capPropertyToV4L2(int 
         return V4L2_CID_HUE;
     case cv::CAP_PROP_GAIN:
         return V4L2_CID_GAIN;
+#ifdef V4L2_CID_EXPOSURE_ABSOLUTE
     case cv::CAP_PROP_EXPOSURE:
         return V4L2_CID_EXPOSURE_ABSOLUTE;
+#endif
     case cv::CAP_PROP_CONVERT_RGB:
         return -1;
     case cv::CAP_PROP_WHITE_BALANCE_BLUE_U:
@@ -1604,8 +1629,10 @@ static inline int capPropertyToV4L2(int 
         return -1;
     case cv::CAP_PROP_SHARPNESS:
         return V4L2_CID_SHARPNESS;
+#ifdef V4L2_CID_EXPOSURE_AUTO
     case cv::CAP_PROP_AUTO_EXPOSURE:
         return V4L2_CID_EXPOSURE_AUTO;
+#endif
     case cv::CAP_PROP_GAMMA:
         return V4L2_CID_GAMMA;
     case cv::CAP_PROP_TEMPERATURE:
@@ -1616,34 +1643,54 @@ static inline int capPropertyToV4L2(int 
         return -1;
     case cv::CAP_PROP_WHITE_BALANCE_RED_V:
         return V4L2_CID_RED_BALANCE;
+#ifdef V4L2_CID_ZOOM_ABSOLUTE
     case cv::CAP_PROP_ZOOM:
         return V4L2_CID_ZOOM_ABSOLUTE;
+#endif
+#ifdef V4L2_CID_FOCUS_ABSOLUTE
     case cv::CAP_PROP_FOCUS:
         return V4L2_CID_FOCUS_ABSOLUTE;
+#endif
     case cv::CAP_PROP_GUID:
         return -1;
+#ifdef V4L2_CID_ISO_SENSITIVITY
     case cv::CAP_PROP_ISO_SPEED:
         return V4L2_CID_ISO_SENSITIVITY;
+#endif
     case cv::CAP_PROP_BACKLIGHT:
         return V4L2_CID_BACKLIGHT_COMPENSATION;
+#ifdef V4L2_CID_PAN_ABSOLUTE
     case cv::CAP_PROP_PAN:
         return V4L2_CID_PAN_ABSOLUTE;
+#endif
+#ifdef V4L2_CID_TILT_ABSOLUTE
     case cv::CAP_PROP_TILT:
         return V4L2_CID_TILT_ABSOLUTE;
+#endif
+#ifdef V4L2_CID_ROTATE
     case cv::CAP_PROP_ROLL:
         return V4L2_CID_ROTATE;
+#endif
+#ifdef V4L2_CID_IRIS_ABSOLUTE
     case cv::CAP_PROP_IRIS:
         return V4L2_CID_IRIS_ABSOLUTE;
+#endif
     case cv::CAP_PROP_SETTINGS:
         return -1;
     case cv::CAP_PROP_BUFFERSIZE:
         return -1;
+#ifdef V4L2_CID_FOCUS_AUTO
     case cv::CAP_PROP_AUTOFOCUS:
         return V4L2_CID_FOCUS_AUTO;
+#endif
+#ifdef V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_HEIGHT
     case cv::CAP_PROP_SAR_NUM:
         return V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_HEIGHT;
+#endif
+#ifdef V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_WIDTH
     case cv::CAP_PROP_SAR_DEN:
         return V4L2_CID_MPEG_VIDEO_H264_VUI_EXT_SAR_WIDTH;
+#endif
     case CAP_PROP_AUTO_WB:
         return V4L2_CID_AUTO_WHITE_BALANCE;
     case CAP_PROP_WB_TEMPERATURE:
