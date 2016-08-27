$NetBSD: patch-src_rrd__cgi.c,v 1.1 2016/08/27 07:40:23 dholland Exp $

Use <ctype.h> correctly.

--- src/rrd_cgi.c~	2016-04-19 15:52:25.000000000 +0000
+++ src/rrd_cgi.c
@@ -1223,7 +1223,7 @@ int parse(
         return 0;
     }
     /* .. and match exactly (a whitespace following 'tag') */
-    if (!isspace(*((*buf) + i + taglen))) {
+    if (!isspace((unsigned char) *((*buf) + i + taglen))) {
         return 0;
     }
 #ifdef DEBUG_PARSER
@@ -1334,10 +1334,10 @@ char     *rrdcgiDecodeString(
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
