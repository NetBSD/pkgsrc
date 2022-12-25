$NetBSD: patch-src_core_fileinfo.c,v 1.1 2022/12/25 17:55:14 wiz Exp $

Fix build on NetBSD with SSP.

--- src/core/fileinfo.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/fileinfo.c
@@ -3206,7 +3206,7 @@ file_info_retrieve(void)
 	if (!f)
 		return;
 
-	while (fgets(ARYLEN(line), f)) {
+	while (fgets(line, sizeof(line), f)) {
 		int error;
 		bool truncated = FALSE, damaged;
 		const char *ep;
