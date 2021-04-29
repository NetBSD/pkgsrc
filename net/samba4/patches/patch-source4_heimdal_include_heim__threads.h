$NetBSD: patch-source4_heimdal_include_heim__threads.h,v 1.2 2021/04/29 15:21:16 taca Exp $

On SunOS (OpenSolaris), pthread_mutex_init() expects a zeroed-out
mutex data structure

--- source4/heimdal/include/heim_threads.h.orig	2019-01-15 10:07:00.000000000 +0000
+++ source4/heimdal/include/heim_threads.h
@@ -87,7 +87,7 @@
 
 #define HEIMDAL_MUTEX pthread_mutex_t
 #define HEIMDAL_MUTEX_INITIALIZER PTHREAD_MUTEX_INITIALIZER
-#define HEIMDAL_MUTEX_init(m) pthread_mutex_init(m, NULL)
+#define HEIMDAL_MUTEX_init(m) memset(m, 0, sizeof(pthread_mutex_t));pthread_mutex_init(m, NULL)
 #define HEIMDAL_MUTEX_lock(m) pthread_mutex_lock(m)
 #define HEIMDAL_MUTEX_unlock(m) pthread_mutex_unlock(m)
 #define HEIMDAL_MUTEX_destroy(m) pthread_mutex_destroy(m)
