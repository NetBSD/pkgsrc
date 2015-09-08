$NetBSD: patch-mutex_mut__method.c,v 1.1 2015/09/08 18:51:27 joerg Exp $

--- mutex/mut_method.c.orig	2015-08-29 23:35:02.000000000 +0000
+++ mutex/mut_method.c
@@ -426,7 +426,7 @@ atomic_compare_exchange(env, v, oldval, 
 	MUTEX_LOCK(env, mtx);
 	ret = atomic_read(v) == oldval;
 	if (ret)
-		atomic_init(v, newval);
+		db_atomic_init(v, newval);
 	MUTEX_UNLOCK(env, mtx);
 
 	return (ret);
