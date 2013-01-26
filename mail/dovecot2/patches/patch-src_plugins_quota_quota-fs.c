$NetBSD: patch-src_plugins_quota_quota-fs.c,v 1.2 2013/01/26 19:38:54 bouyer Exp $

Support NetBSD's libquota

--- src/plugins/quota/quota-fs.c.orig	2012-10-30 18:57:35.000000000 +0100
+++ src/plugins/quota/quota-fs.c	2013-01-26 19:51:09.000000000 +0100
@@ -526,7 +526,8 @@
 }
 #endif
 
-#if defined(FS_QUOTA_LINUX) || defined(FS_QUOTA_BSDAIX)
+#if defined(FS_QUOTA_LINUX) || defined(FS_QUOTA_BSDAIX) || \
+    defined(FS_QUOTA_NETBSD)
 static void fs_quota_root_disable(struct fs_quota_root *root, bool group)
 {
 	if (group)
@@ -642,6 +643,49 @@
 }
 #endif
 
+#ifdef FS_QUOTA_NETBSD
+static int
+fs_quota_get_netbsd(struct fs_quota_root *root, bool group, bool bytes,
+		    uint64_t *value_r, uint64_t *limit_r)
+{
+	struct quotahandle *qh;
+	struct quotakey qk;
+	struct quotaval qv;
+	int ret;
+
+	if ((qh = quota_open(root->mount->mount_path)) == NULL) {
+		i_error("cannot open quota for %s: %m",
+			root->mount->mount_path);
+		fs_quota_root_disable(root, group);
+		return 0;
+	}
+
+	qk.qk_idtype = group ? QUOTA_IDTYPE_GROUP : QUOTA_IDTYPE_USER;
+	qk.qk_id = group ? root->gid : root->uid;
+	qk.qk_objtype = bytes ? QUOTA_OBJTYPE_BLOCKS : QUOTA_OBJTYPE_FILES;
+
+	if (quota_get(qh, &qk, &qv) != 0) {
+		if (errno == EOPNOTSUPP || errno == ENXIO) {
+			fs_quota_root_disable(root, group);
+			ret = 0;
+			goto end;
+		}
+		i_error("quotactl(Q_GETQUOTA, %s) failed: %m",
+			root->mount->mount_path);
+		ret = -1;
+		goto end;
+	}
+
+	*value_r = qv.qv_usage * DEV_BSIZE;
+	*limit_r = qv.qv_softlimit * DEV_BSIZE;
+
+	ret = 1;
+end:
+	quota_close(qh);
+	return ret;
+}
+#endif
+
 #ifdef FS_QUOTA_HPUX
 static int
 fs_quota_get_hpux(struct fs_quota_root *root, bool bytes,
@@ -715,6 +759,8 @@
 	}
 #ifdef FS_QUOTA_LINUX
 	return fs_quota_get_linux(root, group, bytes, value_r, limit_r);
+#elif defined (FS_QUOTA_NETBSD)
+	return fs_quota_get_netbsd(root, group, bytes, value_r, limit_r);
 #elif defined (FS_QUOTA_BSDAIX)
 	return fs_quota_get_bsdaix(root, group, bytes, value_r, limit_r);
 #else
