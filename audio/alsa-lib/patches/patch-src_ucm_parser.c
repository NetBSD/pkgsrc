$NetBSD: patch-src_ucm_parser.c,v 1.4 2016/04/15 08:47:50 wiz Exp $

* SunOS has no dirent d_type

--- src/ucm/parser.c.orig	2013-07-08 12:31:36.000000000 +0000
+++ src/ucm/parser.c
@@ -1224,9 +1224,17 @@ int uc_mgr_import_master_config(snd_use_
 
 static int filename_filter(const struct dirent *dirent)
 {
+#ifdef __sun
+	struct stat s;
+#endif
 	if (dirent == NULL)
 		return 0;
+#ifdef __sun
+	stat(dirent->d_name, &s);
+	if (s.st_mode & S_IFDIR) {
+#else
 	if (dirent->d_type == DT_DIR) {
+#endif
 		if (dirent->d_name[0] == '.') {
 			if (dirent->d_name[1] == '\0')
 				return 0;
