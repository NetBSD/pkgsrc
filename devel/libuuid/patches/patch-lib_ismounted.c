$NetBSD: patch-lib_ismounted.c,v 1.3 2026/09/12 11:49:22 wiz Exp $

Fix build on NetBSD.

--- lib/ismounted.c.orig	2026-08-04 10:59:56.351680370 +0000
+++ lib/ismounted.c
@@ -215,7 +215,11 @@ static int check_getmntinfo(const char *file, int *mou
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
