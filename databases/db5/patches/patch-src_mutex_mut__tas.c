$NetBSD: patch-src_mutex_mut__tas.c,v 1.1 2015/09/08 18:51:28 joerg Exp $

--- src/mutex/mut_tas.c.orig	2015-09-02 11:12:55.000000000 +0000
+++ src/mutex/mut_tas.c
@@ -47,7 +47,7 @@ __db_tas_mutex_init(env, mutex, flags)
 
 #ifdef HAVE_SHARED_LATCHES
 	if (F_ISSET(mutexp, DB_MUTEX_SHARED))
-		atomic_init(&mutexp->sharecount, 0);
+		db_atomic_init(&mutexp->sharecount, 0);
 	else
 #endif
 	if (MUTEX_INIT(&mutexp->tas)) {
@@ -536,7 +536,7 @@ __db_tas_mutex_unlock(env, mutex)
 			F_CLR(mutexp, DB_MUTEX_LOCKED);
 			/* Flush flag update before zeroing count */
 			MEMBAR_EXIT();
-			atomic_init(&mutexp->sharecount, 0);
+			db_atomic_init(&mutexp->sharecount, 0);
 		} else {
 			DB_ASSERT(env, sharecount > 0);
 			MEMBAR_EXIT();
