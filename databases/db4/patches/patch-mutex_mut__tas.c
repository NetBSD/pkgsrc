$NetBSD: patch-mutex_mut__tas.c,v 1.1 2015/09/09 11:11:45 joerg Exp $

--- mutex/mut_tas.c.orig	2015-08-29 23:35:00.000000000 +0000
+++ mutex/mut_tas.c
@@ -46,7 +46,7 @@ __db_tas_mutex_init(env, mutex, flags)
 
 #ifdef HAVE_SHARED_LATCHES
 	if (F_ISSET(mutexp, DB_MUTEX_SHARED))
-		atomic_init(&mutexp->sharecount, 0);
+		db_atomic_init(&mutexp->sharecount, 0);
 	else
 #endif
 	if (MUTEX_INIT(&mutexp->tas)) {
@@ -486,7 +486,7 @@ __db_tas_mutex_unlock(env, mutex)
 			F_CLR(mutexp, DB_MUTEX_LOCKED);
 			/* Flush flag update before zeroing count */
 			MEMBAR_EXIT();
-			atomic_init(&mutexp->sharecount, 0);
+			db_atomic_init(&mutexp->sharecount, 0);
 		} else {
 			DB_ASSERT(env, sharecount > 0);
 			MEMBAR_EXIT();
