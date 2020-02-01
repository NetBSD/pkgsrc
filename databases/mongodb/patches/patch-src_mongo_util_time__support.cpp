$NetBSD: patch-src_mongo_util_time__support.cpp,v 1.2 2020/02/01 20:00:08 adam Exp $

Add support for NetBSD, OpenBSD, and DragonFly.

--- src/mongo/util/time_support.cpp.orig	2019-12-04 23:29:59.000000000 +0000
+++ src/mongo/util/time_support.cpp
@@ -952,7 +952,7 @@ private:
 // Find minimum timer resolution of OS
 Nanoseconds getMinimumTimerResolution() {
     Nanoseconds minTimerResolution;
-#if defined(__linux__) || defined(__FreeBSD__) || defined(__EMSCRIPTEN__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__EMSCRIPTEN__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
     struct timespec tp;
     clock_getres(CLOCK_REALTIME, &tp);
     minTimerResolution = Nanoseconds{tp.tv_nsec};
