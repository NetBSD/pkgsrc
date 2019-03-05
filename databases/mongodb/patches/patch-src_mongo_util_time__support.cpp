$NetBSD: patch-src_mongo_util_time__support.cpp,v 1.1 2019/03/05 19:35:58 adam Exp $

Add support for NetBSD, OpenBSD, and DragonFly.

--- src/mongo/util/time_support.cpp.orig	2019-03-04 22:11:39.324289612 +0000
+++ src/mongo/util/time_support.cpp
@@ -938,7 +938,7 @@ private:
 // Find minimum timer resolution of OS
 Nanoseconds getMinimumTimerResolution() {
     Nanoseconds minTimerResolution;
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__DragonFly__) || defined(__NetBSD__) || defined(__OpenBSD__)
     struct timespec tp;
     clock_getres(CLOCK_REALTIME, &tp);
     minTimerResolution = Nanoseconds{tp.tv_nsec};
