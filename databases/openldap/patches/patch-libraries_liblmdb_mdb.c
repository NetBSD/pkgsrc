$NetBSD: patch-libraries_liblmdb_mdb.c,v 1.1 2016/06/17 14:01:58 jperkin Exp $

Apply https://www.gulag.ch/www/download/0001-Solaris-robust-mutex-fix.patch

--- libraries/liblmdb/mdb.c.orig	2016-02-05 23:57:45.000000000 +0000
+++ libraries/liblmdb/mdb.c
@@ -257,7 +257,7 @@ typedef SSIZE_T	ssize_t;
 # else
 #  define MDB_USE_ROBUST	1
 /* glibc < 2.12 only provided _np API */
-#  if defined(__GLIBC__) && GLIBC_VER < 0x02000c
+#  if (defined(__GLIBC__) && GLIBC_VER < 0x02000a) || defined(__SunOS_5_10)
 #   define PTHREAD_MUTEX_ROBUST	PTHREAD_MUTEX_ROBUST_NP
 #   define pthread_mutexattr_setrobust(attr, flag)	pthread_mutexattr_setrobust_np(attr, flag)
 #   define pthread_mutex_consistent(mutex)	pthread_mutex_consistent_np(mutex)
@@ -4623,10 +4623,21 @@ mdb_env_setup_locks(MDB_env *env, char *
 			|| (rc = pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED))
 #ifdef MDB_ROBUST_SUPPORTED
 			|| (rc = pthread_mutexattr_setrobust(&mattr, PTHREAD_MUTEX_ROBUST))
-#endif
+#else
+	#ifndef __sun
 			|| (rc = pthread_mutex_init(env->me_txns->mti_rmutex, &mattr))
-			|| (rc = pthread_mutex_init(env->me_txns->mti_wmutex, &mattr)))
+			|| (rc = pthread_mutex_init(env->me_txns->mti_wmutex, &mattr))
+	#endif
+#endif
+			) {
 			goto fail;
+		}
+	#ifdef __sun
+		rc = pthread_mutex_init(env->me_txns->mti_rmutex, &mattr);
+		if (!(rc == EBUSY || rc == EINVAL)) goto fail;
+		rc = pthread_mutex_init(env->me_txns->mti_wmutex, &mattr);
+		if (!(rc == EBUSY || rc == EINVAL)) goto fail;
+	#endif
 		pthread_mutexattr_destroy(&mattr);
 #endif	/* _WIN32 || MDB_USE_POSIX_SEM */
 
