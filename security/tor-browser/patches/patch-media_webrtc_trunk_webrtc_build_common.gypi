$NetBSD: patch-media_webrtc_trunk_webrtc_build_common.gypi,v 1.1 2016/02/14 07:30:54 ryoon Exp $

--- media/webrtc/trunk/webrtc/build/common.gypi.orig	2014-04-18 02:03:52.000000000 +0000
+++ media/webrtc/trunk/webrtc/build/common.gypi
@@ -256,7 +256,7 @@
       }],
       ['OS=="dragonfly" or OS=="netbsd"', {
         'defines': [
-          # doesn't support pthread_condattr_setclock
+          # doesn't support pthread_condattr_setclock, NetBSD 6 supports it.
           'WEBRTC_CLOCK_TYPE_REALTIME',
         ],
       }],
