$NetBSD: patch-src_core_downloads.c,v 1.2 2022/12/25 18:08:51 wiz Exp $

Fix build on NetBSD with SSP.
https://github.com/gtk-gnutella/gtk-gnutella/pull/35

--- src/core/downloads.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/downloads.c
@@ -15067,7 +15067,7 @@ download_retrieve_old(FILE *f)
 	d_name = NULL;
 	flags = 0;
 
-	while (fgets(ARYLEN(dl_tmp), f)) {
+	while (fgets(dl_tmp, sizeof(dl_tmp), f)) {
 		line++;
 
 		if (!file_line_chomp_tail(ARYLEN(dl_tmp), NULL)) {
