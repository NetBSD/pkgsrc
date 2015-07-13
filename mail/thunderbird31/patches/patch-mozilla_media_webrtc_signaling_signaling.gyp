$NetBSD: patch-mozilla_media_webrtc_signaling_signaling.gyp,v 1.1 2015/07/13 17:49:26 ryoon Exp $

--- mozilla/media/webrtc/signaling/signaling.gyp.orig	2014-07-18 00:05:39.000000000 +0000
+++ mozilla/media/webrtc/signaling/signaling.gyp
@@ -847,14 +847,13 @@
             ['OS=="mac"', {
               'defines' : [
                 'SIP_OS_OSX',
-                '_POSIX_SOURCE',
+                # using BSD extensions, leave _POSIX_SOURCE undefined
                 'CPR_MEMORY_LITTLE_ENDIAN',
                 'NO_SOCKET_POLLING',
                 'USE_TIMER_SELECT_BASED',
                 'FULL_BUILD',
                 'STUBBED_OUT',
                 'USE_PRINTF',
-                '_DARWIN_C_SOURCE',
                 'NO_NSPR_10_SUPPORT',
               ],
             }],
