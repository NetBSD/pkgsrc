$NetBSD: patch-src_config.h,v 1.1 2020/05/03 11:31:39 adam Exp $

Support pthread_setname_np() on NetBSD.

--- src/config.h.orig	2020-05-03 10:34:02.787449751 +0000
+++ src/config.h
@@ -230,9 +230,12 @@ void setproctitle(const char *fmt, ...);
 #ifdef __linux__
 #define redis_set_thread_title(name) pthread_setname_np(pthread_self(), name)
 #else
-#if (defined __NetBSD__ || defined __FreeBSD__ || defined __OpenBSD__)
+#if (defined __FreeBSD__ || defined __OpenBSD__)
 #include <pthread_np.h>
 #define redis_set_thread_title(name) pthread_set_name_np(pthread_self(), name)
+#elif defined __NetBSD__
+#include <pthread.h>
+#define redis_set_thread_title(name) pthread_setname_np(pthread_self(), name, NULL)
 #else
 #if (defined __APPLE__ && defined(MAC_OS_X_VERSION_10_7))
 int pthread_setname_np(const char *name);
