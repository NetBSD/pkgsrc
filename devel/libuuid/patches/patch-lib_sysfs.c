$NetBSD: patch-lib_sysfs.c,v 1.2 2024/12/28 14:10:24 wiz Exp $

Fix ctype(3) abuse.

--- lib/sysfs.c.orig	2024-06-27 10:10:35.311994946 +0000
+++ lib/sysfs.c
@@ -233,8 +233,8 @@ int sysfs_blkdev_is_partition_dirent(DIR
 		/* partitions subdir name is
 		 *	"<parent>[:digit:]" or "<parent>p[:digit:]"
 		 */
-		return ((*(d->d_name + len) == 'p' && isdigit(*(d->d_name + len + 1)))
-			|| isdigit(*(d->d_name + len)));
+		return ((*(d->d_name + len) == 'p' && isdigit((unsigned char)*(d->d_name + len + 1)))
+ 			|| isdigit((unsigned char)*(d->d_name + len)));
 	}
 
 	/* Cannot use /partition file, not supported on old sysfs */
