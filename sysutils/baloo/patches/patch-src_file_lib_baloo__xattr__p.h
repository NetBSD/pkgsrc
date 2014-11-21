$NetBSD: patch-src_file_lib_baloo__xattr__p.h,v 1.1 2014/11/21 10:44:53 jmcneill Exp $

--- src/file/lib/baloo_xattr_p.h.orig	2014-11-06 12:03:28.000000000 +0000
+++ src/file/lib/baloo_xattr_p.h
@@ -34,6 +34,7 @@
 #elif defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
 #include <sys/types.h>
 #include <sys/extattr.h>
+#include <sys/xattr.h>
 #endif
 
 inline ssize_t baloo_getxattr(const QString& path, const QString& name, QString* value)
