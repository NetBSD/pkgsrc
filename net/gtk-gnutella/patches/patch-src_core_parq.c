$NetBSD: patch-src_core_parq.c,v 1.2 2022/12/25 18:08:51 wiz Exp $

Fix build on NetBSD with SSP.
https://github.com/gtk-gnutella/gtk-gnutella/pull/35

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
