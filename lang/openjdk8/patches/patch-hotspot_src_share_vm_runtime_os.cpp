$NetBSD: patch-hotspot_src_share_vm_runtime_os.cpp,v 1.1 2021/07/23 12:18:23 jperkin Exp $

SunOS does not have tm_gmtoff.

--- hotspot/src/share/vm/runtime/os.cpp.orig	2021-05-14 21:52:06.000000000 +0000
+++ hotspot/src/share/vm/runtime/os.cpp
@@ -148,7 +148,7 @@ char* os::iso8601_time(char* buffer, siz
   const time_t seconds_per_hour = seconds_per_minute * minutes_per_hour;
 
   time_t UTC_to_local = 0;
-#if defined(_ALLBSD_SOURCE) || defined(_GNU_SOURCE)
+#if (defined(_ALLBSD_SOURCE) || defined(_GNU_SOURCE)) && !defined(__sun)
     UTC_to_local = -(time_struct.tm_gmtoff);
 #elif defined(_WINDOWS)
   long zone;
