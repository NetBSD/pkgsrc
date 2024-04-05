$NetBSD: patch-src_libgit2_path.c,v 1.3 2024/04/05 17:03:59 wiz Exp $

Ensure proper value range for tolower() argument.

--- src/libgit2/path.c.orig	2023-04-12 12:05:25.000000000 +0000
+++ src/libgit2/path.c
@@ -202,7 +202,7 @@ GIT_INLINE(size_t) common_prefix_icase(c
 {
 	size_t count = 0;
 
-	while (len > 0 && tolower(*str) == tolower(*prefix)) {
+	while (len > 0 && tolower((unsigned char)*str) == tolower((unsigned char)*prefix)) {
 		count++;
 		str++;
 		prefix++;
