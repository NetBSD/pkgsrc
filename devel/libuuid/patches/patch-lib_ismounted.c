$NetBSD: patch-lib_ismounted.c,v 1.2 2024/12/28 14:10:24 wiz Exp $

Fix build on NetBSD.

--- lib/ismounted.c.orig	2024-01-31 10:02:15.456811591 +0000
+++ lib/ismounted.c
@@ -215,7 +215,11 @@ static int check_mntent(const char *file
 static int check_getmntinfo(const char *file, int *mount_flags,
 				  char *mtpt, int mtlen)
 {
+#ifdef __NetBSD__
+	struct statvfs *mp;
+#else
 	struct statfs *mp;
+#endif
         int    len, n;
         const  char   *s1;
 	char	*s2;
