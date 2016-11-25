$NetBSD: patch-libraries_liblmdb_mdb.c,v 1.1 2016/11/25 15:50:13 fhajny Exp $

Backport upstream fix for SunOS.

https://github.com/LMDB/lmdb/commit/c367c1f69685a4d307acb8cea6945c1d67e1cc7e.patch

Check for PTHREAD_MUTEX_ROBUST_NP definition (this doesn't work
on Linux/glibc because they used an enum). Zero out mutex before
initing.

--- libraries/liblmdb/mdb.c.orig	2016-02-05 21:22:15.000000000 +0000
+++ libraries/liblmdb/mdb.c
@@ -257,7 +257,8 @@ typedef SSIZE_T	ssize_t;
 # else
 #  define MDB_USE_ROBUST	1
 /* glibc < 2.12 only provided _np API */
-#  if defined(__GLIBC__) && GLIBC_VER < 0x02000c
+#  if (defined(__GLIBC__) && GLIBC_VER < 0x02000c) || \
+	(defined(PTHREAD_MUTEX_ROBUST_NP) && !defined(PTHREAD_MUTEX_ROBUST))
 #   define PTHREAD_MUTEX_ROBUST	PTHREAD_MUTEX_ROBUST_NP
 #   define pthread_mutexattr_setrobust(attr, flag)	pthread_mutexattr_setrobust_np(attr, flag)
 #   define pthread_mutex_consistent(mutex)	pthread_mutex_consistent_np(mutex)
@@ -4619,6 +4620,13 @@ mdb_env_setup_locks(MDB_env *env, char *
 #else	/* MDB_USE_POSIX_MUTEX: */
 		pthread_mutexattr_t mattr;
 
+		/* Solaris needs this before initing a robust mutex.  Otherwise
+		 * it may skip the init and return EBUSY "seems someone already
+		 * inited" or EINVAL "it was inited differently".
+		 */
+		memset(env->me_txns->mti_rmutex, 0, sizeof(*env->me_txns->mti_rmutex));
+		memset(env->me_txns->mti_wmutex, 0, sizeof(*env->me_txns->mti_wmutex));
+
 		if ((rc = pthread_mutexattr_init(&mattr))
 			|| (rc = pthread_mutexattr_setpshared(&mattr, PTHREAD_PROCESS_SHARED))
 #ifdef MDB_ROBUST_SUPPORTED
