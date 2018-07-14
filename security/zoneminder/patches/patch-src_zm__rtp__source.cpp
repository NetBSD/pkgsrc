$NetBSD: patch-src_zm__rtp__source.cpp,v 1.2 2018/07/14 15:03:57 gdt Exp $

--- src/zm_rtp_source.cpp.orig	2015-02-05 02:52:37.000000000 +0000
+++ src/zm_rtp_source.cpp
@@ -197,7 +197,7 @@ void RtpSource::updateRtcpData( uint32_t
 {
     struct timeval ntpTime = tvMake( ntpTimeSecs, suseconds_t((USEC_PER_SEC*(ntpTimeFrac>>16))/(1<<16)) );
 
-    Debug( 5, "ntpTime: %ld.%06ld, rtpTime: %x", ntpTime.tv_sec, ntpTime.tv_usec, rtpTime );
+    Debug( 5, "ntpTime: %jd.%06ld, rtpTime: %x", (intmax_t) ntpTime.tv_sec, ntpTime.tv_usec, rtpTime );
                                                      
     if ( mBaseTimeNtp.tv_sec == 0 )
     {
@@ -207,8 +207,8 @@ void RtpSource::updateRtcpData( uint32_t
     }
     else if ( !mRtpClock )
     {
-        Debug( 5, "lastSrNtpTime: %ld.%06ld, rtpTime: %x", mLastSrTimeNtp.tv_sec, mLastSrTimeNtp.tv_usec, rtpTime );
-        Debug( 5, "ntpTime: %ld.%06ld, rtpTime: %x", ntpTime.tv_sec, ntpTime.tv_usec, rtpTime );
+      Debug( 5, "lastSrNtpTime: %jd.%06ld, rtpTime: %x", (intmax_t) mLastSrTimeNtp.tv_sec, mLastSrTimeNtp.tv_usec, rtpTime );
+        Debug( 5, "ntpTime: %jd.%06ld, rtpTime: %x", (intmax_t) ntpTime.tv_sec, ntpTime.tv_usec, rtpTime );
 
         double diffNtpTime = tvDiffSec( mBaseTimeNtp, ntpTime );
         uint32_t diffRtpTime = rtpTime - mBaseTimeRtp;
