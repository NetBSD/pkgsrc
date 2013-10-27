$NetBSD: patch-src_celengine_astro.cpp,v 1.1 2013/10/27 21:21:26 dholland Exp $

Handle a tzname incompatibility between BSD and Linux.

--- src/celengine/astro.cpp~	2011-06-05 16:11:09.000000000 +0000
+++ src/celengine/astro.cpp
@@ -522,7 +522,8 @@ const char* astro::Date::toCStr(Format f
     cal_time.tm_sec = (int)seconds;
     cal_time.tm_wday = wday;
     cal_time.tm_gmtoff = utc_offset;
-#if defined(TARGET_OS_MAC) || defined(__FreeBSD__)
+#if defined(TARGET_OS_MAC) || defined(__FreeBSD__) || defined(__NetBSD__) || \
+	defined(__OpenBSD__) || defined(__DragonFly__)
     // tm_zone is a non-const string field on the Mac and FreeBSD (why?)
     cal_time.tm_zone = const_cast<char*>(tzname.c_str());
 #else
