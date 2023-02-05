$NetBSD: patch-third__party_libwebrtc_modules_video__capture_linux_device__info__linux.cc,v 1.1 2023/02/05 09:05:29 he Exp $

--- third_party/libwebrtc/modules/video_capture/linux/device_info_linux.cc.orig	2020-08-28 21:33:15.000000000 +0000
+++ third_party/libwebrtc/modules/video_capture/linux/device_info_linux.cc
@@ -385,11 +385,15 @@ bool DeviceInfoLinux::IsDeviceNameMatche
 
 bool DeviceInfoLinux::IsVideoCaptureDevice(struct v4l2_capability* cap)
 {
+#ifdef V4L2_CAP_DEVICE_CAPS
   if (cap->capabilities & V4L2_CAP_DEVICE_CAPS) {
     return cap->device_caps & V4L2_CAP_VIDEO_CAPTURE;
   } else {
     return cap->capabilities & V4L2_CAP_VIDEO_CAPTURE;
   }
+#else
+  return 1;
+#endif
 }
 
 int32_t DeviceInfoLinux::FillCapabilities(int fd) {
