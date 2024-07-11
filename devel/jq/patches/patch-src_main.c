$NetBSD: patch-src_main.c,v 1.1 2024/07/11 19:59:08 riastradh Exp $

Fix ctype(3) abuse.
https://github.com/jqlang/jq/issues/3151
https://github.com/jqlang/jq/pull/3152

--- src/main.c.orig	2023-12-13 19:24:02.000000000 +0000
+++ src/main.c
@@ -126,7 +126,7 @@ static void die() {
 }
 
 static int isoptish(const char* text) {
-  return text[0] == '-' && (text[1] == '-' || isalpha(text[1]));
+  return text[0] == '-' && (text[1] == '-' || isalpha((unsigned char)text[1]));
 }
 
 static int isoption(const char* text, char shortopt, const char* longopt, size_t *short_opts) {
