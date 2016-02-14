$NetBSD: patch-media_webrtc_trunk_webrtc_modules_desktop__capture_screen__capturer.cc,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/desktop_capture/screen_capturer.cc.orig	2014-10-11 09:06:41.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/desktop_capture/screen_capturer.cc
@@ -18,7 +18,7 @@ ScreenCapturer* ScreenCapturer::Create()
   return Create(DesktopCaptureOptions::CreateDefault());
 }
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
 ScreenCapturer* ScreenCapturer::CreateWithXDamage(
     bool use_update_notifications) {
   DesktopCaptureOptions options;
