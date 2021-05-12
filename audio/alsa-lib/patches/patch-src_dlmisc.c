$NetBSD: patch-src_dlmisc.c,v 1.1 2021/05/12 14:12:13 ryoon Exp $

* Fix !DL_ORIGIN_AVAILABLE case.
  https://github.com/alsa-project/alsa-lib/commit/ad8c8e5503980295dd8e5e54a6285d2d7e32eb1e
  https://github.com/alsa-project/alsa-lib/commit/1d993b37ab4e0b9b6e6b795d7be84ce97b29e20b

--- src/dlmisc.c.orig	2020-10-19 09:45:13.000000000 +0000
+++ src/dlmisc.c
@@ -42,13 +42,11 @@
 #ifndef PIC
 struct snd_dlsym_link *snd_dlsym_start = NULL;
 #endif
-#ifdef DL_ORIGIN_AVAILABLE
 static int snd_plugin_dir_set = 0;
 static char *snd_plugin_dir = NULL;
 #endif
-#endif
 
-#if defined(DL_ORIGIN_AVAILABLE) && defined(HAVE_LIBPTHREAD)
+#ifdef HAVE_LIBPTHREAD
 static pthread_mutex_t snd_dlpath_mutex = PTHREAD_MUTEX_INITIALIZER;
 
 static inline void snd_dlpath_lock(void)
@@ -442,12 +440,10 @@ void snd_dlobj_cache_cleanup(void)
 		free(c);
 	}
 	snd_dlobj_unlock();
-#ifdef DL_ORIGIN_AVAILABLE
 	snd_dlpath_lock();
 	snd_plugin_dir_set = 0;
 	free(snd_plugin_dir);
 	snd_plugin_dir = NULL;
 	snd_dlpath_unlock();
-#endif
 }
 #endif
