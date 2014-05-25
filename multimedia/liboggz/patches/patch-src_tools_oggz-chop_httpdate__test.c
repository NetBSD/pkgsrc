$NetBSD: patch-src_tools_oggz-chop_httpdate__test.c,v 1.1 2014/05/25 16:35:18 rodent Exp $

Fix build for {Free,Open}BSD.

--- src/tools/oggz-chop/httpdate_test.c.orig	2010-01-30 05:55:59.000000000 +0000
+++ src/tools/oggz-chop/httpdate_test.c
@@ -13,6 +13,7 @@ main (int argc, char * argv[])
   char * d_in = "Mon, 06 Feb 2006 11:20:01 GMT";
   char d_out[30];
   time_t t;
+  struct timezone tzone;
 
   INFO ("Parsing date:");
   INFO (d_in);
@@ -21,7 +22,7 @@ main (int argc, char * argv[])
   if (t == (time_t)-1) {
     FAIL ("Parse error");
   } else {
-    t -= timezone;
+    t -= tzone.tz_minuteswest;
     httpdate_snprint (d_out, 30, t);
 
     INFO ("Output date:");
