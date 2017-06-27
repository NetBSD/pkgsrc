$NetBSD: patch-src_ucm_parser.c,v 1.7 2017/06/27 15:51:39 jperkin Exp $

* SunOS has no dirent d_type

--- src/ucm/parser.c.orig	2017-06-01 06:27:36.000000000 +0000
+++ src/ucm/parser.c
@@ -1476,7 +1476,13 @@ static int filename_filter(const struct
 {
 	if (dirent == NULL)
 		return 0;
+#ifdef __sun
+	struct stat s;
+	stat(dirent->d_name, &s);
+	if (s.st_mode & S_IFDIR) {
+#else
 	if (dirent->d_type == DT_DIR) {
+#endif
 		if (dirent->d_name[0] == '.') {
 			if (dirent->d_name[1] == '\0')
 				return 0;
