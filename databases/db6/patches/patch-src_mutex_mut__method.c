$NetBSD: patch-src_mutex_mut__method.c,v 1.1 2015/09/08 18:51:28 joerg Exp $

--- src/mutex/mut_method.c.orig	2015-09-02 11:18:11.000000000 +0000
+++ src/mutex/mut_method.c
@@ -501,7 +501,7 @@ atomic_compare_exchange(env, v, oldval, 
 	MUTEX_LOCK(env, mtx);
 	ret = atomic_read(v) == oldval;
 	if (ret)
-		atomic_init(v, newval);
+		db_atomic_init(v, newval);
 	MUTEX_UNLOCK(env, mtx);
 
 	return (ret);
