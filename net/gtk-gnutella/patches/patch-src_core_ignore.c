$NetBSD: patch-src_core_ignore.c,v 1.1 2022/12/25 17:55:14 wiz Exp $

Fix build on NetBSD with SSP.

--- src/core/ignore.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/ignore.c
@@ -165,7 +165,7 @@ sha1_parse(FILE *f, const char *file)
 
 	g_assert(f);
 
-	while (fgets(ARYLEN(ign_tmp), f)) {
+	while (fgets(ign_tmp, sizeof(ign_tmp), f)) {
 		line++;
 
 		if (!file_line_chomp_tail(ARYLEN(ign_tmp), &len)) {
@@ -241,7 +241,7 @@ namesize_parse(FILE *f, const char *file
 
 	g_assert(f);
 
-	while (fgets(ARYLEN(ign_tmp), f)) {
+	while (fgets(ign_tmp, sizeof(ign_tmp), f)) {
 		line++;
 
 		if (!file_line_chomp_tail(ARYLEN(ign_tmp), NULL)) {
