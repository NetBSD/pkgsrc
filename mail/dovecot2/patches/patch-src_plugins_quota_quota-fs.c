$NetBSD: patch-src_plugins_quota_quota-fs.c,v 1.1 2013/01/19 05:25:51 manu Exp $

Support NetBSD's libquota

--- src/plugins/quota/quota-fs.c.orig	2013-01-18 18:05:57.000000000 +0100
+++ src/plugins/quota/quota-fs.c	2013-01-18 18:41:46.000000000 +0100
@@ -76,8 +76,11 @@
 
 	unsigned int inode_per_mail:1;
 	unsigned int user_disabled:1;
 	unsigned int group_disabled:1;
+#ifdef FS_QUOTA_NETBSD
+	struct quotahandle *qh;
+#endif
 };
 
 extern struct quota_backend quota_backend_fs;
 
@@ -525,9 +528,10 @@
 #endif
 }
 #endif
 
-#if defined(FS_QUOTA_LINUX) || defined(FS_QUOTA_BSDAIX)
+#if defined(FS_QUOTA_LINUX) || defined(FS_QUOTA_BSDAIX) || \
+    defined(FS_QUOTA_NETBSD)
 static void fs_quota_root_disable(struct fs_quota_root *root, bool group)
 {
 	if (group)
 		root->group_disabled = TRUE;
@@ -641,8 +645,46 @@
 	return 1;
 }
 #endif
 
+#ifdef FS_QUOTA_NETBSD
+static int
+fs_quota_get_netbsd(struct fs_quota_root *root, bool group, bool bytes,
+		    uint64_t *value_r, uint64_t *limit_r)
+{
+	struct quotakey qk;
+	struct quotaval qv;
+
+	if (root->qh == NULL) {
+		if ((root->qh = quota_open(root->mount->mount_path)) == NULL) {
+			i_error("cannot open quota for %s: %m",
+				root->mount->mount_path);
+			fs_quota_root_disable(root, group);
+			return 0;
+		}
+	} 
+
+	qk.qk_idtype = group ? QUOTA_IDTYPE_GROUP : QUOTA_IDTYPE_USER;
+	qk.qk_id = group ? root->gid : root->uid;
+	qk.qk_objtype = bytes ? QUOTA_OBJTYPE_BLOCKS : QUOTA_OBJTYPE_FILES;
+
+	if (quota_get(root->qh, &qk, &qv) != 0) {
+		if (errno == ESRCH) {
+			fs_quota_root_disable(root, group);
+			return 0;
+		}
+		i_error("quotactl(Q_GETQUOTA, %s) failed: %m",
+			root->mount->mount_path);
+		return -1;
+	}
+
+	*value_r = qv.qv_usage * DEV_BSIZE;
+	*limit_r = qv.qv_softlimit * DEV_BSIZE;
+
+	return 1;
+}
+#endif
+
 #ifdef FS_QUOTA_HPUX
 static int
 fs_quota_get_hpux(struct fs_quota_root *root, bool bytes,
 		  uint64_t *value_r, uint64_t *limit_r)
@@ -714,8 +756,10 @@
 			return 0;
 	}
 #ifdef FS_QUOTA_LINUX
 	return fs_quota_get_linux(root, group, bytes, value_r, limit_r);
+#elif defined (FS_QUOTA_NETBSD)
+	return fs_quota_get_netbsd(root, group, bytes, value_r, limit_r);
 #elif defined (FS_QUOTA_BSDAIX)
 	return fs_quota_get_bsdaix(root, group, bytes, value_r, limit_r);
 #else
 	if (group) {
