$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_build_common.gypi,v 1.1 2017/04/27 13:38:19 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/build/common.gypi.orig	2016-04-07 21:33:23.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/build/common.gypi
@@ -335,7 +335,7 @@
       }],
       ['OS=="dragonfly" or OS=="netbsd"', {
         'defines': [
-          # doesn't support pthread_condattr_setclock
+          # doesn't support pthread_condattr_setclock, NetBSD 6 supports it.
           'WEBRTC_CLOCK_TYPE_REALTIME',
         ],
       }],
