$NetBSD: patch-src_libutil_util.c,v 1.1 2018/03/13 15:09:15 fhajny Exp $

Fix SunOS workaround.

--- src/libutil/util.c.orig	2018-03-12 16:46:32.000000000 +0000
+++ src/libutil/util.c
@@ -2766,8 +2766,8 @@ rspamd_gmtime (gint64 ts, struct tm *des
 	dest->tm_sec = remsecs % 60;
 #if !defined(__sun)
 	dest->tm_gmtoff = 0;
-#endif
 	dest->tm_zone = "GMT";
+#endif
 }
 
 #ifdef HAVE_SANE_TZSET
@@ -2787,8 +2787,8 @@ void rspamd_localtime (gint64 ts, struct
 
 	ts += timezone;
 	rspamd_gmtime (ts, dest);
-	dest->tm_zone = daylight ? (tzname[1] ? tzname[1] : tzname[0]) : tzname[0];
 #if !defined(__sun)
+	dest->tm_zone = daylight ? (tzname[1] ? tzname[1] : tzname[0]) : tzname[0];
 	dest->tm_gmtoff = timezone;
 #endif
 }
