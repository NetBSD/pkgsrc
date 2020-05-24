$NetBSD: patch-src_filed_bacl.c,v 1.1 2020/05/24 01:22:16 joerg Exp $

--- src/filed/bacl.c.orig	2020-05-23 22:26:28.106204817 +0000
+++ src/filed/bacl.c
@@ -757,7 +757,7 @@ void *new_bacl()
    return new BACL_OSX();
 #elif defined(HAVE_LINUX_OS)
    return new BACL_Linux();
-#elif defined(HAVE_FREEBSD_OS)
+#elif defined(HAVE_FREEBSD_OS) || defined(HAVE_NETBSD_OS)
    return new BACL_FreeBSD();
 #elif defined(HAVE_HURD_OS)
    return new BACL_Hurd();
