$NetBSD: patch-src_ntfs-3g.c,v 1.1 2015/11/10 17:45:22 adam Exp $

NetBSD is missing some functions, so omit them.

--- src/ntfs-3g.c.orig	2015-11-10 16:54:17.000000000 +0000
+++ src/ntfs-3g.c
@@ -3706,8 +3706,10 @@ static struct fuse *mount_fuse(char *par
 	if (!fh)
 		goto err;
 	
+#if !defined(__NetBSD__)
 	if (fuse_set_signal_handlers(fuse_get_session(fh)))
 		goto err_destory;
+#endif
 out:
 	fuse_opt_free_args(&args);
 	return fh;
