$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_modules_desktop__capture_screen__capturer.h,v 1.1 2015/07/09 15:17:34 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/modules/desktop_capture/screen_capturer.h.orig	2015-06-08 17:49:25.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/modules/desktop_capture/screen_capturer.h
@@ -63,7 +63,7 @@ class ScreenCapturer : public DesktopCap
   static ScreenCapturer* Create(const DesktopCaptureOptions& options);
   static ScreenCapturer* Create();
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
   // Creates platform-specific capturer and instructs it whether it should use
   // X DAMAGE support.
   static ScreenCapturer* CreateWithXDamage(bool use_x_damage);
