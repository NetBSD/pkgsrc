$NetBSD: patch-src_plugins_quota_quota-fs.c,v 1.4 2013/08/05 23:12:42 bouyer Exp $

fix support for NetBSD's libquota

--- src/plugins/quota/quota-fs.c.orig	2013-02-26 09:42:04.000000000 +0100
+++ src/plugins/quota/quota-fs.c	2013-08-06 01:00:32.000000000 +0200
@@ -672,34 +672,38 @@
 {
 	struct quotakey qk;
 	struct quotaval qv;
+	struct quotahandle *qh;
+	int ret;
 
-	if (root->qh == NULL) {
-		if ((root->qh = quota_open(root->mount->mount_path)) == NULL) {
-			i_error("cannot open quota for %s: %m",
-				root->mount->mount_path);
-			fs_quota_root_disable(root, group);
-			return 0;
-		}
-	} 
+	if ((qh = quota_open(root->mount->mount_path)) == NULL) {
+		i_error("cannot open quota for %s: %m",
+			root->mount->mount_path);
+		fs_quota_root_disable(root, group);
+		return 0;
+	}
 
 	qk.qk_idtype = group ? QUOTA_IDTYPE_GROUP : QUOTA_IDTYPE_USER;
 	qk.qk_id = group ? root->gid : root->uid;
 	qk.qk_objtype = bytes ? QUOTA_OBJTYPE_BLOCKS : QUOTA_OBJTYPE_FILES;
 
-	if (quota_get(root->qh, &qk, &qv) != 0) {
+	if (quota_get(qh, &qk, &qv) != 0) {
 		if (errno == ESRCH) {
 			fs_quota_root_disable(root, group);
 			return 0;
 		}
 		i_error("quotactl(Q_GETQUOTA, %s) failed: %m",
 			root->mount->mount_path);
-		return -1;
+		ret = -1;
+		goto end;
 	}
 
 	*value_r = qv.qv_usage * DEV_BSIZE;
 	*limit_r = qv.qv_softlimit * DEV_BSIZE;
 
-	return 1;
+	ret = 1;
+end:
+	quota_close(qh);
+	return ret;
 }
 #endif
 
