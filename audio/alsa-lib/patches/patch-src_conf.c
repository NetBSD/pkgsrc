$NetBSD: patch-src_conf.c,v 1.4 2016/02/18 15:15:57 wiz Exp $

* NetBSD has no PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
* SunOS has no versionsort or dirent d_type

--- src/conf.c.orig	2015-11-09 07:39:18.000000000 +0000
+++ src/conf.c
@@ -3419,11 +3419,19 @@ static int snd_config_hooks(snd_config_t
 
 static int config_filename_filter(const struct dirent *dirent)
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
@@ -3549,7 +3557,7 @@ int snd_config_hook_load(snd_config_t *r
 			int n;
 
 #ifndef DOC_HIDDEN
-#ifdef _GNU_SOURCE
+#if defined(_GNU_SOURCE) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__sun)
 #define SORTFUNC	versionsort
 #else
 #define SORTFUNC	alphasort
