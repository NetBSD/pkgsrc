$NetBSD: patch-crypto.c,v 1.1 2026/10/29 08:42:23 plunky Exp $

Fix ctype(3) abuse

--- crypto.c.orig	2026-10-28 19:19:53.656102037 +0000
+++ crypto.c
@@ -4593,7 +4593,7 @@ static time_t parse_rfc3339_timestamp(const char *str)
         return (time_t)-1;
     str += n;
     str += strspn(str, ".0123456789");
-    if (toupper(*str) != 'Z') {
+    if (toupper(*(unsigned char *)str) != 'Z') {
         int tz, tzh, tzm;
         if (strlen(str) < 6 ||
             sscanf(str + 1, "%2d:%2d", &tzh, &tzm) != 2)
