$NetBSD: patch-src_lockdown.c,v 1.1 2026/05/02 07:01:15 vins Exp $

Fix ctype(3) usage.
https://github.com/libimobiledevice/libimobiledevice/pull/1700

--- src/lockdown.c.orig	2025-07-31 18:39:12.420822229 +0000
+++ src/lockdown.c
@@ -1487,7 +1487,7 @@ static void str_remove_spaces(char *sour
 {
 	char *dest = source;
 	while (*source != 0) {
-		if (!isspace(*source)) {
+		if (!isspace((unsigned char)*source)) {
 			*dest++ = *source; /* copy */
 		}
 		source++;
