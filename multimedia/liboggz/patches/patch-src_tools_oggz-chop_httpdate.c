$NetBSD: patch-src_tools_oggz-chop_httpdate.c,v 1.2 2016/01/03 20:54:50 markd Exp $

Fix build for {Free,Open}BSD.

--- src/tools/oggz-chop/httpdate.c.orig	2010-01-30 05:55:59.000000000 +0000
+++ src/tools/oggz-chop/httpdate.c
@@ -33,6 +33,9 @@ time_t
 httpdate_parse (char * s, int n)
 {
   struct tm d;
+#ifndef __linux__
+  struct timezone tzone;
+#endif
   char wday[3], month[3];
   int i;
 
@@ -60,7 +63,11 @@ httpdate_parse (char * s, int n)
 
   d.tm_year -= 1900;
 
+#ifdef __linux__
   d.tm_sec -= timezone;
+#else
+  d.tm_sec -= (tzone.tz_minuteswest * 60);
+#endif
 
   return mktime (&d);
 }
