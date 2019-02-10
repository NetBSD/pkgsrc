$NetBSD: patch-src_AudioIO.cpp,v 1.3 2019/02/10 17:14:42 nia Exp $

CLOCK_MONOTONIC_RAW is Linux-specific.

--- src/AudioIO.cpp.orig	2018-02-14 07:11:20.000000000 +0000
+++ src/AudioIO.cpp
@@ -985,7 +985,11 @@ static double SystemTime(bool usingAlsa)
    if (usingAlsa) {
       struct timespec now;
       // CLOCK_MONOTONIC_RAW is unaffected by NTP or adj-time
+#ifdef CLOCK_MONOTONIC_RAW
       clock_gettime(CLOCK_MONOTONIC_RAW, &now);
+#else
+      clock_gettime(CLOCK_MONOTONIC, &now);
+#endif
       //return now.tv_sec + now.tv_nsec * 0.000000001;
       return (now.tv_sec + now.tv_nsec * 0.000000001) - streamStartTime;
    }
