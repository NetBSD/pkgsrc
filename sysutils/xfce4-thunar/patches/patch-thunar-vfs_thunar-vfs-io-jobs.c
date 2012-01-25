$NetBSD: patch-thunar-vfs_thunar-vfs-io-jobs.c,v 1.1 2012/01/25 23:37:17 tez Exp $

Per PR#45871 Solaris derived OSs haven't DEFFILEMODE defined
so define it if it is not defined.

--- thunar-vfs/thunar-vfs-io-jobs.c.orig	2012-01-25 23:28:41.920049200 +0000
+++ thunar-vfs/thunar-vfs-io-jobs.c
@@ -60,6 +60,9 @@
 #endif
 
 
+#ifndef DEFFILEMODE
+#define DEFFILEMODE (S_IRUSR|S_IWUSR|S_IRGRP|S_IWGRP|S_IROTH|S_IWOTH)
+#endif
 
 static GList *tvij_collect_nofollow (ThunarVfsJob *job,
                                      GList        *base_path_list,
