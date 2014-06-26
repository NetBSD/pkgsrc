$NetBSD: patch-src_ucm_parser.c,v 1.3 2014/06/26 20:23:14 asau Exp $

* NetBSD has no versionsort
* FreeBSD doesn't have it either
* SunOS has no versionsort or dirent d_type

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
@@ -1254,7 +1262,7 @@ int uc_mgr_scan_master_configs(const cha
 		"%s", env ? env : ALSA_USE_CASE_DIR);
 	filename[MAX_FILE-1] = '\0';
 
-#ifdef _GNU_SOURCE
+#if defined(_GNU_SOURCE) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__sun)
 #define SORTFUNC	versionsort
 #else
 #define SORTFUNC	alphasort
