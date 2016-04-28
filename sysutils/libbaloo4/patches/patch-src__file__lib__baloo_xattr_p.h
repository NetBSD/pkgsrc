$NetBSD: patch-src__file__lib__baloo_xattr_p.h,v 1.1 2016/04/28 07:01:13 markd Exp $

--- src/file/lib/baloo_xattr_p.h.orig	2014-11-06 12:03:28.000000000 +0000
+++ src/file/lib/baloo_xattr_p.h
@@ -117,7 +117,7 @@ inline int baloo_removexattr(const QStri
     #elif defined(Q_OS_MAC)
         return removexattr(encodedPath, attributeName, XATTR_NOFOLLOW );
     #elif defined(Q_OS_FREEBSD) || defined(Q_OS_NETBSD)
-        return removexattr (encodedPath, attributeName);
+        return extattr_delete_file (encodedPath, EXTATTR_NAMESPACE_USER, attributeName);
     #else
         return -1;
     #endif
