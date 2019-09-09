$NetBSD: patch-mtab.c,v 1.1 2019/09/09 09:32:37 nia Exp $

Support NetBSD's spelling of statfs.

--- mtab.c.orig	2017-10-05 01:30:02.000000000 +0000
+++ mtab.c
@@ -132,7 +132,11 @@ fail:
 
 #elif BFS_MNTINFO
 
+#ifdef __NetBSD__
+	struct statvfs *mntbuf;
+#else
 	struct statfs *mntbuf;
+#endif
 	int size = getmntinfo(&mntbuf, MNT_WAIT);
 	if (size < 0) {
 		return NULL;
@@ -150,7 +154,11 @@ fail:
 	}
 	mtab->capacity = size;
 
+#ifdef __NetBSD__
+	for (struct statvfs *mnt = mntbuf; mnt < mntbuf + size; ++mnt) {
+#else
 	for (struct statfs *mnt = mntbuf; mnt < mntbuf + size; ++mnt) {
+#endif
 		struct stat sb;
 		if (stat(mnt->f_mntonname, &sb) != 0) {
 			continue;
