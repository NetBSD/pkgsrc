$NetBSD: patch-src_rrd__cgi.c,v 1.2 2017/07/27 18:31:20 adam Exp $

Use <ctype.h> correctly.

--- src/rrd_cgi.c.orig	2017-05-16 12:26:46.000000000 +0000
+++ src/rrd_cgi.c
@@ -1209,7 +1209,7 @@ static int parse(
         return 0;
     }
     /* .. and match exactly (a whitespace following 'tag') */
-    if (!isspace(*((*buf) + i + taglen))) {
+    if (!isspace((unsigned char) *((*buf) + i + taglen))) {
         return 0;
     }
 #ifdef DEBUG_PARSER
@@ -1308,10 +1308,10 @@ static char *rrdcgiDecodeString(
         if (*cp == '%') {
             if (strchr("0123456789ABCDEFabcdef", *(cp + 1))
                 && strchr("0123456789ABCDEFabcdef", *(cp + 2))) {
-                if (islower(*(cp + 1)))
-                    *(cp + 1) = toupper(*(cp + 1));
-                if (islower(*(cp + 2)))
-                    *(cp + 2) = toupper(*(cp + 2));
+                if (islower((unsigned char) *(cp + 1)))
+                    *(cp + 1) = toupper((unsigned char) *(cp + 1));
+                if (islower((unsigned char) *(cp + 2)))
+                    *(cp + 2) = toupper((unsigned char) *(cp + 2));
                 *(xp) =
                     (*(cp + 1) >=
                      'A' ? *(cp + 1) - 'A' + 10 : *(cp + 1) - '0') * 16 +
