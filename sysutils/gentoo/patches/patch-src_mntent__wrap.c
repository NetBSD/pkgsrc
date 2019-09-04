$NetBSD: patch-src_mntent__wrap.c,v 1.1 2019/09/04 17:35:45 nia Exp $

NetBSD is special and spells it statvfs.

--- src/mntent_wrap.c.orig	2014-03-14 20:25:05.000000000 +0000
+++ src/mntent_wrap.c
@@ -115,7 +115,11 @@ static FILE	f_fstab, f_mtab;
 ** a call to getmntinfo(). The mtab_pos and mtab_num integers are then used to
 ** keep track of where in the returned array of statfs structs we are.
 */
+#ifdef __NetBSD__
+static struct statvfs	*mtab = NULL;
+#else
 static struct statfs	*mtab = NULL;
+#endif
 static guint		mtab_pos = 0, mtab_num = 0;
 
 /* 1999-05-09 -	An attempt at a BSD implementation, after having received input from
