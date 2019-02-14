$NetBSD: patch-src_calibre_utils_speedup.c,v 1.1 2019/02/14 12:16:48 wiz Exp $

Fix build on NetBSD.

--- src/calibre/utils/speedup.c.orig	2019-02-01 17:43:29.000000000 +0000
+++ src/calibre/utils/speedup.c
@@ -502,6 +502,8 @@ extern int pthread_setname_np(const char
 #elif defined(FREEBSD_SET_NAME)
 // Function has a different name on FreeBSD
 void pthread_set_name_np(pthread_t tid, const char *name);
+#elif defined(__NetBSD__)
+// pthread.h provides the symbol
 #else
 // Need _GNU_SOURCE for pthread_setname_np on linux and that causes other issues on systems with old glibc
 extern int pthread_setname_np(pthread_t, const char *name);
@@ -526,6 +528,8 @@ set_thread_name(PyObject *self, PyObject
 #elif defined(FREEBSD_SET_NAME)
 		pthread_set_name_np(pthread_self(), name);
 		ret = 0;
+#elif defined(__NetBSD__)
+		ret = pthread_setname_np(pthread_self(), "%s", name);
 #else
 		ret = pthread_setname_np(pthread_self(), name);
 #endif
