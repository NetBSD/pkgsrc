$NetBSD: patch-src_libguac_pool.c,v 1.1 2022/12/25 18:39:51 wiz Exp $

Avoid using undefined function on NetBSD.

--- src/libguac/pool.c.orig	2018-11-21 09:00:59.000000000 +0000
+++ src/libguac/pool.c
@@ -41,7 +41,9 @@ guac_pool* guac_pool_alloc(int size) {
 
     /* Init lock */
     pthread_mutexattr_init(&lock_attributes);
+#ifndef __NetBSD__
     pthread_mutexattr_setpshared(&lock_attributes, PTHREAD_PROCESS_SHARED);
+#endif
     pthread_mutex_init(&(pool->__lock), &lock_attributes);
 
     return pool;
