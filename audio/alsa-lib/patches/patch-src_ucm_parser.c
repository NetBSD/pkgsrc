$NetBSD: patch-src_ucm_parser.c,v 1.9 2021/06/28 10:10:50 wiz Exp $

* SunOS has no dirent d_type

--- src/ucm/parser.c.orig	2020-06-29 10:51:08.000000000 +0000
+++ src/ucm/parser.c
@@ -2220,7 +2220,13 @@ static int filename_filter(const struct 
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
