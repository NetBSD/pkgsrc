$NetBSD: patch-lib_sysfs.c,v 1.1 2022/04/02 21:00:54 riastradh Exp $

Fix ctype(3) abuse.

--- lib/sysfs.c.orig	2018-07-11 13:34:54.228003727 +0000
+++ lib/sysfs.c
@@ -346,8 +346,9 @@ int sysfs_is_partition_dirent(DIR *dir, 
 		 *	"<parent>[:digit:]" or "<parent>p[:digit:]"
 		 */
 		return strncmp(p, d->d_name, len) == 0 &&
-		       ((*(d->d_name + len) == 'p' && isdigit(*(d->d_name + len + 1)))
-			|| isdigit(*(d->d_name + len)));
+		       ((*(d->d_name + len) == 'p' &&
+			   isdigit((unsigned char)*(d->d_name + len + 1)))
+			|| isdigit((unsigned char)*(d->d_name + len)));
 	}
 
 	/* Cannot use /partition file, not supported on old sysfs */
