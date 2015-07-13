$NetBSD: patch-mozilla_media_webrtc_trunk_webrtc_build_common.gypi,v 1.1 2015/07/13 17:49:26 ryoon Exp $

--- mozilla/media/webrtc/trunk/webrtc/build/common.gypi.orig	2014-07-18 00:05:42.000000000 +0000
+++ mozilla/media/webrtc/trunk/webrtc/build/common.gypi
@@ -256,7 +256,7 @@
       }],
       ['OS=="dragonfly" or OS=="netbsd"', {
         'defines': [
-          # doesn't support pthread_condattr_setclock
+          # doesn't support pthread_condattr_setclock, NetBSD 6 supports it.
           'WEBRTC_CLOCK_TYPE_REALTIME',
         ],
       }],
