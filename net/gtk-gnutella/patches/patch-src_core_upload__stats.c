$NetBSD: patch-src_core_upload__stats.c,v 1.2 2022/12/25 18:08:51 wiz Exp $

Fix build on NetBSD with SSP.
https://github.com/gtk-gnutella/gtk-gnutella/pull/35

--- src/core/upload_stats.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/upload_stats.c
@@ -223,7 +223,7 @@ upload_stats_load_history(void)
 		goto done;
 
 	/* parse, insert names into ul_stats_clist */
-	while (fgets(ARYLEN(line), upload_stats_file)) {
+	while (fgets(line, sizeof(line), upload_stats_file)) {
 		static const struct ul_stats zero_item;
 		struct ul_stats item;
 		struct sha1 sha1_buf;
