$NetBSD: patch-src_core_parq.c,v 1.1 2022/12/25 17:55:14 wiz Exp $

Fix build on NetBSD with SSP.

--- src/core/parq.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/parq.c
@@ -5208,7 +5208,7 @@ parq_upload_load_queue(void)
 	entry = zero_entry;
 	bit_array_init(tag_used, NUM_PARQ_TAGS);
 
-	while (fgets(ARYLEN(line), f)) {
+	while (fgets(line, sizeof(line), f)) {
 		const char *tag_name, *value;
 		char *colon;
 		bool damaged;
