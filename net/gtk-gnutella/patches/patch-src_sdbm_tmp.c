$NetBSD: patch-src_sdbm_tmp.c,v 1.1 2022/12/25 17:55:14 wiz Exp $

Fix build on NetBSD with SSP.

--- src/sdbm/tmp.c.orig	2022-02-25 16:06:22.000000000 +0000
+++ src/sdbm/tmp.c
@@ -219,7 +219,7 @@ tmp_clean_entries(int *fd, const char *e
 	eslist_init(&items, offsetof(struct tmp_entry, next));
 	s = str_new(32);
 
-	while (fgets(ARYLEN(line), f)) {
+	while (fgets(line, sizeof(line), f)) {
 		char *extension;
 		pid_t pid;
 		struct tmp_entry *item;
