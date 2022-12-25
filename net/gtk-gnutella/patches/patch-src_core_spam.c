$NetBSD: patch-src_core_spam.c,v 1.2 2022/12/25 18:08:51 wiz Exp $

Fix build on NetBSD with SSP.
https://github.com/gtk-gnutella/gtk-gnutella/pull/35

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
