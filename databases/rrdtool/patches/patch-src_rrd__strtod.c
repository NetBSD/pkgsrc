$NetBSD: patch-src_rrd__strtod.c,v 1.2 2017/07/27 18:31:20 adam Exp $

Use <ctype.h> correctly.

--- src/rrd_strtod.c.orig	2017-05-16 12:26:46.000000000 +0000
+++ src/rrd_strtod.c
@@ -117,7 +117,7 @@ double rrd_strtod(const char *str, char 
     num_decimals = 0;
 
     // Process string of digits
-    while (isdigit(*p)) {
+    while (isdigit((unsigned char)*p)) {
         number = number * 10. + (*p - '0');
         p++;
         num_digits++;
@@ -127,7 +127,7 @@ double rrd_strtod(const char *str, char 
     if (*p == '.') {
         p++;
 
-        while (isdigit(*p)) {
+        while (isdigit((unsigned char)*p)) {
             number = number * 10. + (*p - '0');
             p++;
             num_digits++;
@@ -156,7 +156,7 @@ double rrd_strtod(const char *str, char 
 
         // Process string of digits
         n = 0;
-        while (isdigit(*p)) {
+        while (isdigit((unsigned char)*p)) {
             n = n * 10 + (*p - '0');
             p++;
         }
