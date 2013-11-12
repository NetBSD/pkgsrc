$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_modules_video__capture_video__capture__factory.cc,v 1.1 2013/11/12 20:50:51 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/modules/video_capture/video_capture_factory.cc.orig	2013-10-23 22:09:13.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/modules/video_capture/video_capture_factory.cc
@@ -8,8 +8,10 @@
  *  be found in the AUTHORS file in the root of the source tree.
  */
 
+_Pragma("GCC visibility push(default)")
 #include "video_capture_factory.h"
 #include "video_capture_impl.h"
+_Pragma("GCC visibility pop")
 
 namespace webrtc
 {
