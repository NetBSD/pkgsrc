$NetBSD: patch-src_plugins_quota_quota-fs.c,v 1.6 2016/04/08 07:55:16 adam Exp $

Fix for missing declaration.

--- src/plugins/quota/quota-fs.c.orig	2016-04-08 07:46:25.000000000 +0000
+++ src/plugins/quota/quota-fs.c
@@ -680,7 +680,7 @@ fs_quota_get_netbsd(struct fs_quota_root
 	struct quotakey qk;
 	struct quotaval qv;
 	struct quotahandle *qh;
-	int ret;
+	int i, ret;
 
 	if ((qh = quota_open(root->mount->mount_path)) == NULL) {
 		i_error("cannot open quota for %s: %m",
