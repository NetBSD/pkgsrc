$NetBSD: patch-mtab.c,v 1.2 2019/12/15 12:29:01 mef Exp $

Support NetBSD's spelling of statfs.

--- mtab.c.orig	2019-09-15 03:10:39.000000000 +0900
+++ mtab.c	2019-12-15 21:00:33.122336837 +0900
@@ -140,14 +140,21 @@ struct bfs_mtab *parse_bfs_mtab() {
 
 #elif BFS_MNTINFO
 
+#ifdef __NetBSD__
+	struct statvfs *mntbuf;
+#else
 	struct statfs *mntbuf;
+#endif
 	int size = getmntinfo(&mntbuf, MNT_WAIT);
 	if (size < 0) {
 		error = errno;
 		goto fail;
 	}
-
+#ifdef __NetBSD__
+	for (struct statvfs *mnt = mntbuf; mnt < mntbuf + size; ++mnt) {
+#else
 	for (struct statfs *mnt = mntbuf; mnt < mntbuf + size; ++mnt) {
+#endif
 		if (bfs_mtab_add(mtab, mnt->f_mntonname, mnt->f_fstypename) != 0) {
 			error = errno;
 			goto fail;
