$NetBSD: patch-src_filed_bxattr.c,v 1.1 2019/02/07 11:29:31 markd Exp $

NetBSD has xattr

--- src/filed/bxattr.c.orig	2018-12-21 08:40:51.000000000 +0000
+++ src/filed/bxattr.c
@@ -922,6 +922,7 @@ bRC_BXATTR BXATTR::unserialize_xattr_str
 #include "bxattr_osx.h"
 #include "bxattr_linux.h"
 #include "bxattr_freebsd.h"
+#include "bxattr_netbsd.h"
 #include "bxattr_solaris.h"
 // #include "bxattr_aix.h"
 
@@ -936,6 +937,8 @@ void *new_bxattr()
    return new BXATTR_Linux();
 #elif defined(HAVE_FREEBSD_OS)
    return new BXATTR_FreeBSD();
+#elif defined(HAVE_NETBSD_OS)
+   return new BXATTR_NetBSD();
 #elif defined(HAVE_HURD_OS)
    return new BXATTR_Hurd();
 #elif defined(HAVE_AIX_OS)
