$NetBSD: patch-src_plugins_quota_quota-fs.c,v 1.7 2018/01/02 15:52:44 fhajny Exp $

Fix for missing declaration.

--- src/plugins/quota/quota-fs.c.orig	2017-12-22 13:53:41.000000000 +0000
+++ src/plugins/quota/quota-fs.c
@@ -700,7 +700,7 @@ fs_quota_get_netbsd(struct fs_quota_root
 	struct quotakey qk;
 	struct quotaval qv;
 	struct quotahandle *qh;
-	int ret;
+	int i, ret;
 
 	if ((qh = quota_open(root->mount->mount_path)) == NULL) {
 		*error_r = t_strdup_printf("cannot open quota for %s: %m",
