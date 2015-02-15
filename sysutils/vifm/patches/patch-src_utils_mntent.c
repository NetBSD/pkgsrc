$NetBSD: patch-src_utils_mntent.c,v 1.1 2015/02/15 12:50:53 ryoon Exp $

* I have no idea how to test this...

--- src/utils/mntent.c.orig	2014-10-25 15:09:35.000000000 +0000
+++ src/utils/mntent.c
@@ -47,7 +47,7 @@
 #include <stdlib.h>
 #include <string.h>
 
-static struct mntent * statfs_to_mntent(struct statfs *mntbuf);
+static struct mntent * statvfs_to_mntent(struct statvfs *mntbuf);
 static char * flags2opts(int flags);
 static char * catopt(char s0[], const char s1[]);
 
@@ -76,7 +76,7 @@ getmntent(FILE *fp)
 	static int pos = -1;
 	static int mntsize = -1;
 
-	static struct statfs *mntbuf;
+	static struct statvfs *mntbuf;
 
 	if(pos == -1 || mntsize == -1)
 	{
@@ -90,11 +90,11 @@ getmntent(FILE *fp)
 		return NULL;
 	}
 
-	return statfs_to_mntent(&mntbuf[pos]);
+	return statvfs_to_mntent(&mntbuf[pos]);
 }
 
 static struct mntent *
-statfs_to_mntent(struct statfs *mntbuf)
+statvfs_to_mntent(struct statvfs *mntbuf)
 {
 	static struct mntent _mntent;
 	static char opts_buf[40], *tmp;
@@ -102,7 +102,7 @@ statfs_to_mntent(struct statfs *mntbuf)
 	_mntent.mnt_fsname = mntbuf->f_mntfromname;
 	_mntent.mnt_dir = mntbuf->f_mntonname;
 	_mntent.mnt_type = mntbuf->f_fstypename;
-	tmp = flags2opts (mntbuf->f_flags);
+	tmp = flags2opts (mntbuf->f_flag);
 	if(tmp != NULL)
 	{
 		opts_buf[sizeof(opts_buf) - 1] = '\0';
@@ -128,7 +128,7 @@ flags2opts(int flags)
 	if(flags & MNT_UNION)       res = catopt(res, "union");
 	if(flags & MNT_ASYNC)       res = catopt(res, "async");
 	if(flags & MNT_NOATIME)     res = catopt(res, "noatime");
-#ifndef __APPLE__
+#if !(defined(__APPLE__) || defined(__NetBSD__))
 	if(flags & MNT_NOCLUSTERR)  res = catopt(res, "noclusterr");
 	if(flags & MNT_NOCLUSTERW)  res = catopt(res, "noclusterw");
 	if(flags & MNT_NOSYMFOLLOW) res = catopt(res, "nosymfollow");
