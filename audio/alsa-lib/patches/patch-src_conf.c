$NetBSD: patch-src_conf.c,v 1.1 2014/06/09 12:21:07 ryoon Exp $

* NetBSD has no PTHREAD_RECURSIVE_MUTEX_INITIALIZER_NP

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
@@ -3506,7 +3519,7 @@ int snd_config_hook_load(snd_config_t *r
 			int n;
 
 #ifndef DOC_HIDDEN
-#ifdef _GNU_SOURCE
+#if defined(_GNU_SOURCE) && !defined(__NetBSD__)
 #define SORTFUNC	versionsort
 #else
 #define SORTFUNC	alphasort
