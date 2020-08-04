$NetBSD: patch-core_src_lmdb_mdb.c,v 1.2 2020/08/04 12:56:15 kardel Exp $

	use POSIX semaphores on NetBSD

--- core/src/lmdb/mdb.c.orig	2020-08-04 12:17:56.368741881 +0000
+++ core/src/lmdb/mdb.c
@@ -150,7 +150,11 @@ typedef SSIZE_T	ssize_t;
 
 #if defined(__APPLE__) || defined (BSD)
 # if !(defined(MDB_USE_POSIX_MUTEX) || defined(MDB_USE_POSIX_SEM))
-# define MDB_USE_SYSV_SEM	1
+#   if defined(__NetBSD__)
+#     define MDB_USE_POSIX_SEM	1
+#   else
+#     define MDB_USE_SYSV_SEM	1
+#   endif
 # endif
 # define MDB_FDATASYNC		fsync
 #elif defined(ANDROID)
