$NetBSD: patch-src_utils_knotc_interactive.c,v 1.2 2026/08/30 09:15:36 drixter Exp $

Fix from upstream to properly compile on SunOS

--- src/utils/knotc/interactive.c.orig	2026-08-29 19:17:24.182700199 +0000
+++ src/utils/knotc/interactive.c
@@ -359,11 +359,16 @@ static void path_lookup(EditLine *el, co
 	struct stat sb;
 	for (int i = 0; i < nnames; ++i) {
 		const struct dirent *it = namelist[i];
+#ifdef __sun
+		strlcpy(base, it->d_name, PATH_MAX - (size_t)(base - path));
+		bool is_dir = !stat(path, &sb) && S_ISDIR(sb.st_mode);
+#else
 		bool is_dir = (it->d_type == DT_DIR);
 		if (it->d_type == DT_LNK) {
 			strlcpy(base, it->d_name, PATH_MAX - (size_t)(base - path));
 			is_dir = !stat(path, &sb) && S_ISDIR(sb.st_mode);
 		}
+#endif
 		if ((!dirsonly || is_dir) &&
 		    (strcmp(it->d_name, ".") && strcmp(it->d_name, ".."))) {
 			char buf[NAME_MAX + 2];  // Max. name length + slash + terminator.
