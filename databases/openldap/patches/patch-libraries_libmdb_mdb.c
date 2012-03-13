$NetBSD: patch-libraries_libmdb_mdb.c,v 1.1 2012/03/13 19:57:11 adam Exp $

--- libraries/libmdb/mdb.c.orig	2012-03-13 19:49:49.000000000 +0000
+++ libraries/libmdb/mdb.c
@@ -2680,10 +2680,12 @@ mdb_env_setup_locks(MDB_env *env, char *
 		pthread_mutexattr_t mattr;
 
 		pthread_mutexattr_init(&mattr);
+#ifdef _POSIX_THREAD_PROCESS_SHARED
 		rc = pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED);
 		if (rc) {
 			goto fail;
 		}
+#endif
 		pthread_mutex_init(&env->me_txns->mti_mutex, &mattr);
 		pthread_mutex_init(&env->me_txns->mti_wmutex, &mattr);
 #endif	/* __APPLE__ */
