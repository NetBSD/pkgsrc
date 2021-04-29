$NetBSD: patch-lib_pthreadpool_pthreadpool.c,v 1.2 2021/04/29 15:21:16 taca Exp $

On SunOS (OpenSolaris), pthread_mutex_init() expects a zeroed-out
mutex data structure

--- lib/pthreadpool/pthreadpool.c.orig	2019-01-15 10:07:00.000000000 +0000
+++ lib/pthreadpool/pthreadpool.c
@@ -153,6 +153,7 @@ int pthreadpool_init(unsigned max_thread
 
 	pool->head = pool->num_jobs = 0;
 
+	memset(&pool->mutex, 0, sizeof(pthread_mutex_t));
 	ret = pthread_mutex_init(&pool->mutex, NULL);
 	if (ret != 0) {
 		free(pool->jobs);
@@ -168,6 +169,7 @@ int pthreadpool_init(unsigned max_thread
 		return ret;
 	}
 
+	memset(&pool->fork_mutex, 0, sizeof(pthread_mutex_t));	
 	ret = pthread_mutex_init(&pool->fork_mutex, NULL);
 	if (ret != 0) {
 		pthread_cond_destroy(&pool->condvar);
