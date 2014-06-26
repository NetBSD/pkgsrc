$NetBSD: patch-src_conf.c,v 1.3 2014/06/26 20:23:14 asau Exp $

* NetBSD has no PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP
* SunOS has no versionsort or dirent d_type

--- src/conf.c.orig	2013-07-08 12:31:36.000000000 +0000
+++ src/conf.c
@@ -426,9 +426,12 @@ beginning:</P>
 
 #ifndef DOC_HIDDEN
 
-#ifdef HAVE_LIBPTHREAD
+#if defined(HAVE_LIBPTHREAD) && defined(PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP)
 static pthread_mutex_t snd_config_update_mutex =
 				PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP;
+#else
+pthread_mutexattr_t attr;
+pthread_mutex_t _mutex;
 #endif
 
 struct _snd_config {
@@ -474,12 +477,22 @@ typedef struct {
 
 static inline void snd_config_lock(void)
 {
+#if defined(PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP)
 	pthread_mutex_lock(&snd_config_update_mutex);
+#else
+	pthread_mutexattr_init(&attr);
+	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
+	pthread_mutex_init(&_mutex, &attr);
+#endif
 }
 
 static inline void snd_config_unlock(void)
 {
+#if defined(PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP)
 	pthread_mutex_unlock(&snd_config_update_mutex);
+#else
+	pthread_mutexattr_destroy(&attr);
+#endif
 }
 
 #else
@@ -3376,11 +3389,19 @@ static int snd_config_hooks(snd_config_t
 
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
@@ -3506,7 +3527,7 @@ int snd_config_hook_load(snd_config_t *r
 			int n;
 
 #ifndef DOC_HIDDEN
-#ifdef _GNU_SOURCE
+#if defined(_GNU_SOURCE) && !defined(__NetBSD__) && !defined(__FreeBSD__) && !defined(__sun)
 #define SORTFUNC	versionsort
 #else
 #define SORTFUNC	alphasort
