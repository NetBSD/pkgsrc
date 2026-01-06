$NetBSD: patch-src_zm__rtp__source.cpp,v 1.6 2026/01/06 17:51:37 gdt Exp $

Fix type issue with tv_sec; see earlier patches.

--- src/zm_rtp_source.cpp.orig	2026-01-06 13:05:00.000000000 +0000
+++ src/zm_rtp_source.cpp
@@ -196,7 +196,7 @@ void RtpSource::updateRtcpData(
     uint32_t rtpTime) {
   struct timeval ntpTime = tvMake(ntpTimeSecs, suseconds_t((USEC_PER_SEC*(ntpTimeFrac>>16))/(1<<16)));
 
-  Debug(5, "ntpTime: %jd.%06ld, rtpTime: %x", static_cast<intmax_t>(ntpTime.tv_sec), ntpTime.tv_usec, rtpTime);
+  Debug(5, "ntpTime: %jd.%06ld, rtpTime: %x", static_cast<intmax_t>(ntpTime.tv_sec), static_cast<long>(ntpTime.tv_usec), rtpTime);
 
   if ( mBaseTimeNtp.tv_sec == 0 ) {
     mBaseTimeReal = tvNow();
@@ -205,8 +205,8 @@ void RtpSource::updateRtcpData(
   } else if ( !mRtpClock ) {
     Debug(5, "lastSrNtpTime: %jd.%06ld, rtpTime: %x"
         "ntpTime: %jd.%06ld, rtpTime: %x",
-        static_cast<intmax_t>( mLastSrTimeNtp.tv_sec), mLastSrTimeNtp.tv_usec, rtpTime,
-        static_cast<intmax_t>(ntpTime.tv_sec), ntpTime.tv_usec, rtpTime);
+        static_cast<intmax_t>( mLastSrTimeNtp.tv_sec), static_cast<long>(mLastSrTimeNtp.tv_usec), rtpTime,
+	static_cast<intmax_t>(ntpTime.tv_sec), static_cast<long>(ntpTime.tv_usec), rtpTime);
 
     double diffNtpTime = tvDiffSec( mBaseTimeNtp, ntpTime );
     uint32_t diffRtpTime = rtpTime - mBaseTimeRtp;
