$NetBSD: patch-src-xattr.c,v 1.1 2015/09/23 12:03:48 joerg Exp $

--- src/xattr.c.orig	2015-07-01 11:45:08.000000000 +0000
+++ src/xattr.c
@@ -265,12 +265,19 @@ int set_xattr(const char *path, struct s
  || defined(HAVE_OPENBSD_OS)
 
 #include <sys/extattr.h>
+#if defined(HAVE_FREEBSD_OS)
 #include <libutil.h>
+#else
+#include <util.h>
+#endif
 
 static int namespaces[2] = { EXTATTR_NAMESPACE_USER, EXTATTR_NAMESPACE_SYSTEM };
 
 #if defined(HAVE_FREEBSD_OS)
 static const char *acl_skiplist[2] = { "system.posix1e.acl_access", NULL };
+#else
+static const char *acl_skiplist[] = { NULL };
+
 #endif
 
 int has_xattr(const char *path, char cmd)
