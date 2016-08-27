$NetBSD: patch-src_rrd__strtod.c,v 1.1 2016/08/27 07:40:23 dholland Exp $

Use <ctype.h> correctly.

--- src/rrd_strtod.c~	2016-04-19 15:52:26.000000000 +0000
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
