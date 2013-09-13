$NetBSD: patch-src_spot_notify.cxx,v 1.2 2013/09/13 06:35:55 mef Exp $

Avoid implicit conversions to bool for streams.
Require C++11 for Clang and prefer std version over tr1 when in C++11
mode.

--- src/spot/notify.cxx.orig	2013-07-06 20:54:45.000000000 +0900
+++ src/spot/notify.cxx	2013-07-07 15:25:39.000000000 +0900
@@ -35,7 +35,10 @@
 
 #include "timeops.h"
 
-#if (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1)
+#if __cplusplus >= 201103L
+#  define MAP_TYPE std::unordered_map
+#  include <unordered_map>
+#elif (__GNUC__ > 4) || (__GNUC__ == 4 && __GNUC_MINOR__ >= 1)
 #  define MAP_TYPE std::tr1::unordered_map
 #  include <tr1/unordered_map>
 #else
