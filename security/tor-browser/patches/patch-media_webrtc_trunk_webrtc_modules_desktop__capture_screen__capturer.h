$NetBSD: patch-media_webrtc_trunk_webrtc_modules_desktop__capture_screen__capturer.h,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/desktop_capture/screen_capturer.h.orig	2014-10-11 09:06:41.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/desktop_capture/screen_capturer.h
@@ -74,7 +74,7 @@ class ScreenCapturer : public DesktopCap
   static ScreenCapturer* Create(const DesktopCaptureOptions& options);
   static ScreenCapturer* Create();
 
-#if defined(WEBRTC_LINUX)
+#if defined(WEBRTC_LINUX) || defined(WEBRTC_BSD)
   // Creates platform-specific capturer and instructs it whether it should use
   // X DAMAGE support.
   static ScreenCapturer* CreateWithXDamage(bool use_x_damage);
