$NetBSD: patch-src_tools_oggz-chop_httpdate__test.c,v 1.2 2016/01/03 20:54:50 markd Exp $

Fix build for {Free,Open}BSD.

--- src/tools/oggz-chop/httpdate_test.c.orig	2010-01-30 05:55:59.000000000 +0000
+++ src/tools/oggz-chop/httpdate_test.c
@@ -13,6 +13,9 @@ main (int argc, char * argv[])
   char * d_in = "Mon, 06 Feb 2006 11:20:01 GMT";
   char d_out[30];
   time_t t;
+#ifndef __linux__
+  struct timezone tzone;
+#endif
 
   INFO ("Parsing date:");
   INFO (d_in);
@@ -21,7 +24,11 @@ main (int argc, char * argv[])
   if (t == (time_t)-1) {
     FAIL ("Parse error");
   } else {
+#ifdef __linux__
     t -= timezone;
+#else
+    t -= tzone.tz_minuteswest;
+#endif
     httpdate_snprint (d_out, 30, t);
 
     INFO ("Output date:");
