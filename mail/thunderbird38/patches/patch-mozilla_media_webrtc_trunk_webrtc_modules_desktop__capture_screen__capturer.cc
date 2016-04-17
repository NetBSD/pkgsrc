$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_modules_desktop__capture_screen__capturer.cc,v 1.1 2016/04/17 18:22:21 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/modules/desktop_capture/screen_capturer.cc.orig	2015-06-08 17:49:25.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/modules/desktop_capture/screen_capturer.cc
@@ -18,7 +18,7 @@ ScreenCapturer* ScreenCapturer::Create()
   return Create(DesktopCaptureOptions::CreateDefault());
 }
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 ScreenCapturer* ScreenCapturer::CreateWithXDamage(
     bool use_update_notifications) {
   DesktopCaptureOptions options;
