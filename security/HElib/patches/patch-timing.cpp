$NetBSD: patch-timing.cpp,v 1.3 2020/06/08 13:47:44 wiz Exp $

NetBSD provides CLOCK_MONOTONIC, but not CLOCK_MONOTONIC_RAW.
https://github.com/homenc/HElib/pull/355

--- timing.cpp.orig	2020-05-04 18:09:21.000000000 +0000
+++ timing.cpp
@@ -18,6 +18,11 @@
 namespace helib {
 
 #ifdef CLOCK_MONOTONIC
+
+#ifndef CLOCK_MONOTONIC_RAW
+#define CLOCK_MONOTONIC_RAW CLOCK_MONOTONIC
+#endif
+
 unsigned long GetTimerClock()
 {
   timespec ts;
