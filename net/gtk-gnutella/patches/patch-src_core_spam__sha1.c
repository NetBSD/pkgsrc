$NetBSD: patch-src_core_spam__sha1.c,v 1.2 2022/12/25 18:08:51 wiz Exp $

Fix build on NetBSD with SSP.
https://github.com/gtk-gnutella/gtk-gnutella/pull/35

--- src/core/spam_sha1.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/spam_sha1.c
@@ -199,7 +199,7 @@ spam_sha1_load(FILE *f)
 	spam_lut_create();
 	sha1_lut.state = SPAM_LOADING;
 
-	while (fgets(ARYLEN(line), f)) {
+	while (fgets(line, sizeof(line), f)) {
 		const struct sha1 *sha1;
 		size_t len;
 
