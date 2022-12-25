$NetBSD: patch-src_core_dmesh.c,v 1.1 2022/12/25 17:55:14 wiz Exp $

Fix build on NetBSD with SSP.

--- src/core/dmesh.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/dmesh.c
@@ -3372,7 +3372,7 @@ dmesh_retrieve(void)
 	 * blank line are attached sources for this SHA1.
 	 */
 
-	while (fgets(ARYLEN(tmp), f)) {
+	while (fgets(tmp, sizeof(tmp), f)) {
 		if (!file_line_chomp_tail(ARYLEN(tmp), NULL)) {
 			truncated = TRUE;
 			continue;
@@ -3486,7 +3486,7 @@ dmesh_ban_retrieve(void)
 	 * Lines starting with a # are skipped.
 	 */
 
-	while (fgets(ARYLEN(tmp), in)) {
+	while (fgets(tmp, sizeof(tmp), in)) {
 		line++;
 
 		if (!file_line_chomp_tail(ARYLEN(tmp), NULL)) {
