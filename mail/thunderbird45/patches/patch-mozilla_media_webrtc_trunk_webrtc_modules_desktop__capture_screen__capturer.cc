$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_modules_desktop__capture_screen__capturer.cc,v 1.1 2017/04/27 13:38:19 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/modules/desktop_capture/screen_capturer.cc.orig	2016-04-07 21:33:24.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/modules/desktop_capture/screen_capturer.cc
@@ -18,7 +18,7 @@ ScreenCapturer* ScreenCapturer::Create()
   return Create(DesktopCaptureOptions::CreateDefault());
 }
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 ScreenCapturer* ScreenCapturer::CreateWithXDamage(
     bool use_update_notifications) {
   DesktopCaptureOptions options;
