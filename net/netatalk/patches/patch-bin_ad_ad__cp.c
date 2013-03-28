$NetBSD: patch-bin_ad_ad__cp.c,v 1.1 2013/03/28 21:36:21 joerg Exp $

--- bin/ad/ad_cp.c.orig	2013-03-28 19:06:20.000000000 +0000
+++ bin/ad/ad_cp.c
@@ -841,7 +841,7 @@ static int setfile(const struct stat *fs
     islink = !fdval && S_ISLNK(fs->st_mode);
     mode = fs->st_mode & (S_ISUID | S_ISGID | S_ISVTX | S_IRWXU | S_IRWXG | S_IRWXO);
 
-#if defined(__FreeBSD__)
+#if defined(__FreeBSD__) || defined(__NetBSD__)
     TIMESPEC_TO_TIMEVAL(&tv[0], &fs->st_atimespec);
     TIMESPEC_TO_TIMEVAL(&tv[1], &fs->st_mtimespec);
 #else
