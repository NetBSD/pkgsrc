$NetBSD: patch-mozilla_ipc_chromium_src_base_time__posix.cc,v 1.1 2017/04/27 13:38:18 ryoon Exp $

--- mozilla/ipc/chromium/src/base/time_posix.cc.orig	2016-04-07 21:33:19.000000000 +0000
+++ mozilla/ipc/chromium/src/base/time_posix.cc
@@ -65,8 +65,10 @@ Time Time::FromExploded(bool is_local, c
   timestruct.tm_wday   = exploded.day_of_week;  // mktime/timegm ignore this
   timestruct.tm_yday   = 0;     // mktime/timegm ignore this
   timestruct.tm_isdst  = -1;    // attempt to figure it out
+#ifndef OS_SOLARIS
   timestruct.tm_gmtoff = 0;     // not a POSIX field, so mktime/timegm ignore
   timestruct.tm_zone   = NULL;  // not a POSIX field, so mktime/timegm ignore
+#endif
 
   time_t seconds;
 #ifdef ANDROID
