$NetBSD: patch-src_tools_oggz-chop_httpdate.c,v 1.1 2014/05/25 16:35:18 rodent Exp $

Fix build for {Free,Open}BSD.

--- src/tools/oggz-chop/httpdate.c.orig	2010-01-30 05:55:59.000000000 +0000
+++ src/tools/oggz-chop/httpdate.c
@@ -33,6 +33,7 @@ time_t
 httpdate_parse (char * s, int n)
 {
   struct tm d;
+  struct timezone tzone;
   char wday[3], month[3];
   int i;
 
@@ -60,7 +61,7 @@ httpdate_parse (char * s, int n)
 
   d.tm_year -= 1900;
 
-  d.tm_sec -= timezone;
+  d.tm_sec -= (tzone.tz_minuteswest * 60);
 
   return mktime (&d);
 }
