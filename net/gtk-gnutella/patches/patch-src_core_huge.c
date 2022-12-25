$NetBSD: patch-src_core_huge.c,v 1.2 2022/12/25 18:08:51 wiz Exp $

Fix build on NetBSD with SSP.
https://github.com/gtk-gnutella/gtk-gnutella/pull/35

--- src/core/huge.c.orig	2022-02-25 16:06:19.000000000 +0000
+++ src/core/huge.c
@@ -402,7 +402,7 @@ sha1_read_cache(void)
 		for (;;) {
 			char buffer[4096];
 
-			if (NULL == fgets(ARYLEN(buffer), f))
+			if (NULL == fgets(buffer, sizeof(buffer), f))
 				break;
 
 			if (!file_line_chomp_tail(ARYLEN(buffer), NULL)) {
