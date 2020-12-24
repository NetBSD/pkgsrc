$NetBSD: patch-src_libltfs_fs.c,v 1.1 2020/12/24 12:01:25 mef Exp $

ICU-68.1 adaptation:
fs.c:266:32: error: 'FALSE' undeclared (first use in this function); did you mean 'FILE'?
   update_platform_safe_name(d, FALSE, idx);
                                ^~~~~
                                FILE

--- src/libltfs/fs.c.orig	2019-02-20 14:22:33.000000000 +0900
+++ src/libltfs/fs.c	2020-12-24 20:57:45.926149247 +0900
@@ -263,7 +263,7 @@
 		d->platform_safe_name = NULL;
 	} else if (name && !platform_safe_name) {
 		d->name.name = strdup(name);
-		update_platform_safe_name(d, FALSE, idx);
+		update_platform_safe_name(d, false, idx);
 		if (! d->name.name || ! d->platform_safe_name) {
 			ltfsmsg(LTFS_ERR, 10001E, "fs_allocate_dentry: name");
 			if (d->name.name)
