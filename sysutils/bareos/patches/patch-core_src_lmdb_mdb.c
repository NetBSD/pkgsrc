$NetBSD: patch-core_src_lmdb_mdb.c,v 1.1 2020/07/28 06:36:29 kardel Exp $

	Fix compilation on NetBSD

--- core/src/lmdb/mdb.c.orig	2018-12-20 08:51:51.000000000 +0000
+++ core/src/lmdb/mdb.c
@@ -150,7 +150,8 @@ typedef SSIZE_T	ssize_t;
 
 #if defined(__APPLE__) || defined (BSD)
 # if !(defined(MDB_USE_POSIX_MUTEX) || defined(MDB_USE_POSIX_SEM))
-# define MDB_USE_SYSV_SEM	1
+/* # define MDB_USE_SYSV_SEM	1 */
+# define MDB_USE_POSIX_SEM	1
 # endif
 # define MDB_FDATASYNC		fsync
 #elif defined(ANDROID)
@@ -4829,7 +4830,7 @@ mdb_env_setup_locks(MDB_env *env, char *
 #endif
 #ifdef MDB_USE_SYSV_SEM
 	int semid;
-	union semun semu;
+	// XXXkd: union semun semu;
 #endif
 	int rc;
 	off_t size, rsize;
