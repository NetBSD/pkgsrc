$NetBSD: patch-src_zm__rtp__source.cpp,v 1.5 2024/12/01 13:49:48 gdt Exp $

Fix type issue with tv_sec; see earlier patches.

--- src/zm_rtp_source.cpp.orig	2023-02-23 21:44:01.000000000 +0000
+++ src/zm_rtp_source.cpp
@@ -196,17 +196,17 @@ void RtpSource::updateRtcpData(
     uint32_t rtpTime) {
   struct timeval ntpTime = tvMake(ntpTimeSecs, suseconds_t((USEC_PER_SEC*(ntpTimeFrac>>16))/(1<<16)));
 
-  Debug(5, "ntpTime: %ld.%06ld, rtpTime: %x", ntpTime.tv_sec, ntpTime.tv_usec, rtpTime);
+  Debug(5, "ntpTime: %jd.%06ld, rtpTime: %x", (intmax_t) ntpTime.tv_sec, (long) ntpTime.tv_usec, rtpTime);
 
   if ( mBaseTimeNtp.tv_sec == 0 ) {
     mBaseTimeReal = tvNow();
     mBaseTimeNtp = ntpTime;
     mBaseTimeRtp = rtpTime;
   } else if ( !mRtpClock ) {
-    Debug(5, "lastSrNtpTime: %ld.%06ld, rtpTime: %x"
-        "ntpTime: %ld.%06ld, rtpTime: %x",
-        mLastSrTimeNtp.tv_sec, mLastSrTimeNtp.tv_usec, rtpTime,
-        ntpTime.tv_sec, ntpTime.tv_usec, rtpTime);
+    Debug(5, "lastSrNtpTime: %jd.%06ld, rtpTime: %x"
+        "ntpTime: %jd.%06ld, rtpTime: %x",
+	(intmax_t) mLastSrTimeNtp.tv_sec, (long) mLastSrTimeNtp.tv_usec, rtpTime,
+        (intmax_t) ntpTime.tv_sec, (long) ntpTime.tv_usec, rtpTime);
 
     double diffNtpTime = tvDiffSec( mBaseTimeNtp, ntpTime );
     uint32_t diffRtpTime = rtpTime - mBaseTimeRtp;
