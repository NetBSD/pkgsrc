$NetBSD: patch-src_core_spam__sha1.c,v 1.1 2022/12/25 17:55:14 wiz Exp $

Fix build on NetBSD with SSP.

--- src/core/spam_sha1.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/spam_sha1.c
@@ -199,7 +199,7 @@ spam_sha1_load(FILE *f)
 	spam_lut_create();
 	sha1_lut.state = SPAM_LOADING;
 
-	while (fgets(ARYLEN(line), f)) {
+	while (fgets(line, sizeof(line), f)) {
 		const struct sha1 *sha1;
 		size_t len;
 
