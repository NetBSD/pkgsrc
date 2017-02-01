$NetBSD: patch-src_utils_mntent.c,v 1.2 2017/02/01 14:17:21 mef Exp $

* I have no idea how to test this...

--- src/compat/mntent.c.orig	2015-10-09 01:52:00.000000000 +0900
+++ src/compat/mntent.c	2017-02-01 22:41:54.000000000 +0900
@@ -53,7 +53,7 @@
 #define f_flags f_flag
 #endif
 
-static struct mntent * statfs_to_mntent(struct statfs *mntbuf);
+static struct mntent * statvfs_to_mntent(struct statfs *mntbuf);
 static char * flags2opts(int flags);
 static char * catopt(char s0[], const char s1[]);
 
@@ -82,7 +82,7 @@ getmntent(FILE *fp)
 	static int pos = -1;
 	static int mntsize = -1;
 
-	static struct statfs *mntbuf;
+	static struct statvfs *mntbuf;
 
 	if(pos == -1 || mntsize == -1)
 	{
@@ -96,11 +96,11 @@ getmntent(FILE *fp)
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
@@ -108,7 +108,7 @@ statfs_to_mntent(struct statfs *mntbuf)
 	_mntent.mnt_fsname = mntbuf->f_mntfromname;
 	_mntent.mnt_dir = mntbuf->f_mntonname;
 	_mntent.mnt_type = mntbuf->f_fstypename;
-	tmp = flags2opts (mntbuf->f_flags);
+	tmp = flags2opts (mntbuf->f_flag);
 	if(tmp != NULL)
 	{
 		opts_buf[sizeof(opts_buf) - 1] = '\0';
