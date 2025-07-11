$NetBSD: patch-internal_fs_node__xattr.go,v 1.1 2025/07/11 19:09:13 pho Exp $

Ignore EOPNOTSUPP that is returned if the filesystem does not support
xattrs on NetBSD:
https://github.com/restic/restic/pull/5344

--- internal/fs/node_xattr.go.orig	2025-07-11 18:57:45.520857611 +0000
+++ internal/fs/node_xattr.go
@@ -53,9 +53,10 @@ func handleXattrErr(err error) error {
 
 	case *xattr.Error:
 		// On Linux, xattr calls on files in an SMB/CIFS mount can return
-		// ENOATTR instead of ENOTSUP.
+		// ENOATTR instead of ENOTSUP.  Ignore "Operation not supported"
+		// as well.
 		switch e.Err {
-		case syscall.ENOTSUP, xattr.ENOATTR:
+		case syscall.ENOTSUP, syscall.EOPNOTSUPP, xattr.ENOATTR:
 			return nil
 		}
 		return errors.WithStack(e)
