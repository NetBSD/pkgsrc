$NetBSD: patch-src_fr-command-lrzip.c,v 1.2 2020/04/05 16:05:40 bsiegert Exp $

* use portable member name

--- src/fr-command-lrzip.c.orig	2020-02-10 11:05:03.000000000 +0000
+++ src/fr-command-lrzip.c
@@ -53,7 +53,7 @@ list__process_line (char     *line,
 	struct stat st;
 
 	if (stat (comm->filename, &st) == 0)
-		fdata->modified = st.st_mtim.tv_sec;
+		fdata->modified = st.st_mtime;
 	else
 		time(&(fdata->modified));
 
