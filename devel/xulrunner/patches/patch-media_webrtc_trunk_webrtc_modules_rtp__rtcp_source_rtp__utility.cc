$NetBSD: patch-media_webrtc_trunk_webrtc_modules_rtp__rtcp_source_rtp__utility.cc,v 1.1 2013/05/19 08:47:41 ryoon Exp $

--- media/webrtc/trunk/webrtc/modules/rtp_rtcp/source/rtp_utility.cc.orig	2013-05-11 19:19:45.000000000 +0000
+++ media/webrtc/trunk/webrtc/modules/rtp_rtcp/source/rtp_utility.cc
@@ -18,7 +18,7 @@
 #include <Windows.h>  // FILETIME
 #include <WinSock.h>  // timeval
 #include <MMSystem.h>  // timeGetTime
-#elif ((defined WEBRTC_LINUX) || (defined WEBRTC_MAC))
+#elif ((defined WEBRTC_LINUX) || (defined WEBRTC_BSD) || (defined WEBRTC_MAC))
 #include <sys/time.h>  // gettimeofday
 #include <time.h>
 #endif
@@ -156,7 +156,7 @@ void get_time(WindowsHelpTimer* help_tim
     WindowsHelpTimer* _helpTimer;
 };
 
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 
 // A clock reading times from the POSIX API.
 class UnixSystemClock : public RtpRtcpClock {
@@ -214,7 +214,7 @@ void WindowsSystemClock::CurrentNTP(WebR
   frac = (WebRtc_UWord32)dtemp;
 }
 
-#elif ((defined WEBRTC_LINUX) || (defined WEBRTC_MAC))
+#elif ((defined WEBRTC_LINUX) || (defined WEBRTC_BSD) || (defined WEBRTC_MAC))
 
 WebRtc_Word64 UnixSystemClock::GetTimeInMS() {
   return TickTime::MillisecondTimestamp();
@@ -253,7 +253,7 @@ static WindowsHelpTimer global_help_time
 RtpRtcpClock* GetSystemClock() {
 #if defined(_WIN32)
   return new WindowsSystemClock(&global_help_timer);
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
   return new UnixSystemClock();
 #else
   return NULL;
@@ -330,7 +330,7 @@ bool StringCompare(const char* str1, con
                    const WebRtc_UWord32 length) {
   return (_strnicmp(str1, str2, length) == 0) ? true : false;
 }
-#elif defined(WEBRTC_LINUX) || defined(WEBRTC_MAC)
+#elif defined(WEBRTC_LINUX) || defined(WEBRTC_BSD) || defined(WEBRTC_MAC)
 bool StringCompare(const char* str1, const char* str2,
                    const WebRtc_UWord32 length) {
   return (strncasecmp(str1, str2, length) == 0) ? true : false;
