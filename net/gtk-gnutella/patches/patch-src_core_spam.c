$NetBSD: patch-src_core_spam.c,v 1.1 2022/12/25 17:55:14 wiz Exp $

Fix build on NetBSD with SSP.

--- src/core/spam.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/spam.c
@@ -221,7 +221,7 @@ spam_load(FILE *f)
 	item = zero_item;
 	bit_array_init(tag_used, NUM_SPAM_TAGS);
 
-	while (fgets(ARYLEN(line), f)) {
+	while (fgets(line, sizeof(line), f)) {
 		const char *tag_name, *value;
 		char *sp;
 		spam_tag_t tag;
