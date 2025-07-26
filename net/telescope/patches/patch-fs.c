$NetBSD: patch-fs.c,v 1.1 2025/07/26 21:41:39 vins Exp $

struct dirent misses a d_type member on SunOS.

--- fs.c.orig	2025-07-26 20:51:03.413194456 +0000
+++ fs.c
@@ -118,10 +118,15 @@ send_dir(struct tab *tab, const char *pa
 
 	for (i = 0; i < len; ++i) {
 		const char *sufx = "";
-
+#ifndef DT_DIR
+		struct stat s;
+		stat(names[i]->d_name, &s);
+		if (S_ISDIR(s.st_mode))
+			sufx = "/";
+#else
 		if (names[i]->d_type == DT_DIR)
 			sufx = "/";
-
+#endif
 		parser_parsef(buffer, "=> %s%s\n", names[i]->d_name, sufx);
 	}
 
