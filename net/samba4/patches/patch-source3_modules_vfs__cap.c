$NetBSD: patch-source3_modules_vfs__cap.c,v 1.1 2025/07/24 15:12:51 tsutsui Exp $

- Fix random coredump on NetBSD/i386 10.1. From FreeBSD ports:
 https://bugs.freebsd.org/275597

--- source3/modules/vfs_cap.c.orig	2025-07-24 02:19:13.963781176 +0000
+++ source3/modules/vfs_cap.c
@@ -110,7 +110,7 @@ cap_readdir(vfs_handle_struct *handle, s
 		return NULL;
 	}
 	talloc_set_name_const(newdirent, "struct dirent");
-	memcpy(newdirent, result, sizeof(struct dirent));
+	memcpy(newdirent, result, result->d_reclen);
 	memcpy(&newdirent->d_name, newname, newnamelen);
 	return newdirent;
 }
