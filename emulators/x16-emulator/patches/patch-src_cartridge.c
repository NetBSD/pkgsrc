$NetBSD: patch-src_cartridge.c,v 1.1 2023/11/27 04:17:30 thorpej Exp $

Safely pass a char to ctype(3) functions.

--- src/cartridge.c.orig	2023-11-27 04:12:57.695843788 +0000
+++ src/cartridge.c	2023-11-27 04:14:00.358575809 +0000
@@ -30,7 +30,7 @@ static int
 x16_strnicmp(char const *s0, char const *s1, int len)
 {
 	for(int i=0; (i<len) && (*s0 && *s1); ++i) {
-		if(tolower(*s0) != tolower(*s1)) {
+		if(tolower((unsigned char)*s0) != tolower((unsigned char)*s1)) {
 			break;
 		}
 		++s0;
@@ -216,7 +216,7 @@ static char *
 rtrim(char *str)
 {
     char *c = str + strlen(str) - 1;
-    while(isspace(*c)) {
+    while(isspace((unsigned char)*c)) {
 		--c;
 	}
     *(c + 1) = '\0';
