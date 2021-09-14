$NetBSD: patch-src_gdbmsync.c,v 1.1 2021/09/14 13:32:50 schmonz Exp $

Apply upstream patch 32517af7 to check for st_mtim in struct stat.
Fixes macOS build.

--- src/gdbmsync.c.orig	2021-08-10 12:13:24.000000000 +0000
+++ src/gdbmsync.c
@@ -220,16 +220,23 @@ gdbm_failure_atomic (GDBM_FILE dbf, cons
 }
 
 static inline int
-timespec_cmp (struct timespec const *a, struct timespec const *b)
+timespec_cmp (struct stat const *a, struct stat const *b)
 {
-  if (a->tv_sec < b->tv_sec)
+#if HAVE_STRUCT_STAT_ST_MTIM
+  if (a->st_mtim.tv_sec < b->st_mtim.tv_sec)
     return -1;
-  if (a->tv_sec > b->tv_sec)
+  if (a->st_mtim.tv_sec > b->st_mtim.tv_sec)
     return 1;
-  if (a->tv_nsec < b->tv_nsec)
+  if (a->st_mtim.tv_nsec < b->st_mtim.tv_nsec)
     return -1;
-  if (a->tv_nsec > b->tv_nsec)
+  if (a->st_mtim.tv_nsec > b->st_mtim.tv_nsec)
     return 1;
+#else
+  if (a->st_mtime < b->st_mtime)
+    return -1;
+  if (a->st_mtime > b->st_mtime)
+    return 1;
+#endif  
   return 0;
 }
 
@@ -374,7 +381,7 @@ gdbm_latest_snapshot (const char *even, 
 	   * Select the newer snapshot, i.e. the one whose mtime
 	   * is greater than the other's
 	   */
-	  switch (timespec_cmp (&st_even.st_mtim, &st_odd.st_mtim))
+	  switch (timespec_cmp (&st_even, &st_odd))
 	    {
 	    case -1:
 	      *ret = odd;
