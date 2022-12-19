$NetBSD: patch-cfs__attach.c,v 1.1 2022/12/19 23:18:37 gdt Exp $

For NetBSD, use statvfs.

\todo Send upstream.

--- cattach.c.orig	2022-12-19 22:34:48.224422733 +0000
+++ cattach.c
@@ -83,8 +83,12 @@ main(int argc, char *argv[])
 	struct fs_data sfb;
 #define f_blocks  fd_req.btot
 #else
+#if defined(__NetBSD_Version__) && __NetBSD_Version__ >= 299000900
+	struct statvfs sfb;
+#else
 	struct statfs sfb;
 #endif
+#endif
 	char *flg;
 	int ciph;
 	FILE *fp;
