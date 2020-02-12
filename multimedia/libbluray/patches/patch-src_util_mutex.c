$NetBSD: patch-src_util_mutex.c,v 1.1 2020/02/12 15:33:37 ryoon Exp $

* Fix segfault on NetBSD/amd64 9.99.46

--- src/util/mutex.c.orig	2019-06-07 18:00:28.000000000 +0000
+++ src/util/mutex.c
@@ -89,7 +89,7 @@ static int _mutex_init(MUTEX_IMPL *p)
 
 static int _mutex_lock(MUTEX_IMPL *p)
 {
-    if (pthread_equal(p->owner, pthread_self())) {
+    if (p->owner == pthread_self()) {
         /* recursive lock */
         p->lock_count++;
         return 0;
@@ -108,7 +108,7 @@ static int _mutex_lock(MUTEX_IMPL *p)
 
 static int _mutex_unlock(MUTEX_IMPL *p)
 {
-    if (!pthread_equal(p->owner, pthread_self())) {
+    if (!(p->owner == pthread_self())) {
         BD_DEBUG(DBG_BLURAY|DBG_CRIT, "bd_mutex_unlock(): not owner !\n");
         return -1;
     }
