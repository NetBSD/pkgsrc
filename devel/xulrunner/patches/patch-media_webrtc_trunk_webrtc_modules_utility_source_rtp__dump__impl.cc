$NetBSD: patch-media_webrtc_trunk_webrtc_modules_utility_source_rtp__dump__impl.cc,v 1.1 2013/05/19 08:47:41 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/utility/source/rtp_dump_impl.cc.orig	2013-05-11 19:19:45.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/utility/source/rtp_dump_impl.cc
@@ -19,7 +19,7 @@
 #if defined(_WIN32)
 #include <Windows.h>
 #include <mmsystem.h>
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 #include <string.h>
 #include <sys/time.h>
 #include <time.h>
@@ -238,7 +238,7 @@ inline WebRtc_UWord32 RtpDumpImpl::GetTi
 {
 #if defined(_WIN32)
     return timeGetTime();
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
     struct timeval tv;
     struct timezone tz;
     unsigned long val;
