$NetBSD: patch-fileio.c,v 1.1 2025/05/23 09:28:50 jperkin Exp $

Support systems that lack DT_DIR and friends.

--- fileio.c.orig	2025-05-23 08:08:06.411929386 +0000
+++ fileio.c
@@ -528,21 +528,28 @@ make_file_list(char *buf)
 	last = NULL;
 
 	while ((dent = readdir(dirp)) != NULL) {
+		struct stat statbuf;
 		int isdir;
 		if (strncmp(cp, dent->d_name, len) != 0)
 			continue;
 		isdir = 0;
+#ifdef DT_DIR
 		if (dent->d_type == DT_DIR) {
 			isdir = 1;
 		} else if (dent->d_type == DT_LNK ||
 			    dent->d_type == DT_UNKNOWN) {
-			struct stat	statbuf;
 
 			if (fstatat(dirfd(dirp), dent->d_name, &statbuf, 0) < 0)
 				continue;
 			if (S_ISDIR(statbuf.st_mode))
 				isdir = 1;
 		}
+#else
+		if (fstatat(dirfd(dirp), dent->d_name, &statbuf, 0) < 0)
+			continue;
+		if (S_ISDIR(statbuf.st_mode))
+			isdir = 1;
+#endif		
 
 		if ((current = malloc(sizeof(struct list))) == NULL) {
 			free_file_list(last);
