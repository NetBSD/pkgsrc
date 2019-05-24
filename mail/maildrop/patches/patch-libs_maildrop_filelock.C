$NetBSD: patch-libs_maildrop_filelock.C,v 1.1 2019/05/24 14:17:17 hauke Exp $

We want to not fail a lock on a device file, make it so 
(patch from FreeBSD mail/maildrop port)
  
--- libs/maildrop/filelock.C.orig	2013-08-25 18:54:20.000000000 +0000
+++ libs/maildrop/filelock.C
@@ -63,7 +63,7 @@ int	flockrc;
 		// you're writing to a device file, you know what you're doing.
 
 		if (fstat(fd, &stat_buf) >= 0 && (
-			S_ISREG(stat_buf.st_mode) || S_ISDIR(stat_buf.st_mode)))
+			S_ISCHR(stat_buf.st_mode) || S_ISBLK(stat_buf.st_mode)))
 		{
 			return;
 		}
