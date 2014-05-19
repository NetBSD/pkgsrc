$NetBSD: patch-include_ntfs-3g_compat.h,v 1.1 2014/05/19 12:22:06 adam Exp $

NetBSD-1.6.2 does not know about ENOTSUP.

--- include/ntfs-3g/compat.h.orig	2013-01-13 06:46:35.000000000 +0000
+++ include/ntfs-3g/compat.h
@@ -71,5 +71,9 @@ extern char *strsep(char **stringp, cons
 
 #endif /* defined WINDOWS */
 
+#ifndef ENOTSUP
+#define ENOTSUP EINVAL
+#endif
+
 #endif /* defined _NTFS_COMPAT_H */
 
