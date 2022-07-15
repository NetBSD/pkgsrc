$NetBSD: patch-src_conf.c,v 1.6 2022/07/15 21:17:25 wiz Exp $

* SunOS has no dirent d_type

--- src/conf.c.orig	2022-06-17 09:42:05.000000000 +0000
+++ src/conf.c
@@ -4066,11 +4066,19 @@ static int snd_config_hooks(snd_config_t
 
 static int config_filename_filter(const struct dirent64 *dirent)
 {
+#ifdef __sun
+	struct stat s;
+#endif
 	size_t flen;
 
 	if (dirent == NULL)
 		return 0;
+#ifdef __sun
+	stat(dirent->d_name, &s);
+	if (s.st_mode & S_IFDIR)
+#else
 	if (dirent->d_type == DT_DIR)
+#endif
 		return 0;
 
 	flen = strlen(dirent->d_name);
