$NetBSD: patch-third__party_heimdal_include_heim__threads.h,v 1.1 2022/07/21 09:35:19 adam Exp $

On SunOS (OpenSolaris), pthread_mutex_init() expects a zeroed-out
mutex data structure

--- third_party/heimdal/include/heim_threads.h.orig	2022-01-24 10:27:00.000000000 +0000
+++ third_party/heimdal/include/heim_threads.h
@@ -110,7 +110,7 @@ typedef unsigned long HEIM_PRIV_thread_k
 
 #define HEIMDAL_MUTEX pthread_mutex_t
 #define HEIMDAL_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER
-#define HEIMDAL_MUTEX_init(m) pthread_mutex_init(m, NULL)
+#define HEIMDAL_MUTEX_init(m) memset(m, 0, sizeof(pthread_mutex_t));pthread_mutex_init(m, NULL)
 #define HEIMDAL_MUTEX_lock(m) pthread_mutex_lock(m)
 #define HEIMDAL_MUTEX_unlock(m) pthread_mutex_unlock(m)
 #define HEIMDAL_MUTEX_destroy(m) pthread_mutex_destroy(m)
