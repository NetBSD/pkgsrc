$NetBSD: patch-src_libgit2_config.c,v 1.1 2023/05/25 15:52:53 he Exp $

Ensure proper value range for arg to isalnum().

--- src/libgit2/config.c.orig	2023-04-12 12:05:25.000000000 +0000
+++ src/libgit2/config.c
@@ -1447,7 +1447,7 @@ static int normalize_section(char *start
 	for (scan = start; *scan; ++scan) {
 		if (end && scan >= end)
 			break;
-		if (isalnum(*scan))
+		if (isalnum((unsigned char)*scan))
 			*scan = (char)git__tolower(*scan);
 		else if (*scan != '-' || scan == start)
 			return GIT_EINVALIDSPEC;
