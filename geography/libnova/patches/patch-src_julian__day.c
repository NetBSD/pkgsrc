$NetBSD: patch-src_julian__day.c,v 1.1 2024/06/10 10:50:32 jperkin Exp $

SunOS does not have gmtoff.

--- src/julian_day.c.orig	2024-06-10 10:48:17.096625904 +0000
+++ src/julian_day.c
@@ -298,7 +298,11 @@ void ln_get_local_date (double JD, struc
 #else
  	curtime = time (NULL);
  	loctime = localtime(&curtime);
+#ifdef __sun
+ 	gmtoff = 0;
+#else
  	gmtoff = loctime->tm_gmtoff;
+#endif
 	// otherwise there is no reasonable way how to get that:(
 	// tm_gmtoff already included DST
 #endif
