$NetBSD: patch-src_util_os__file.c,v 1.1 2026/11/23 10:29:52 adam Exp $

Support NetBSD.

--- src/util/os_file.c.orig	2026-02-19 18:55:18.000000000 +0000
+++ src/util/os_file.c
@@ -320,6 +320,19 @@ error:
    close(efd);
 
    return r;
+#elif DETECT_OS_NETBSD
+   struct stat st1, st2;
+
+   if (fstat(fd1, &st1) != 0)
+      return -1;
+
+   if (fstat(fd2, &st2) != 0)
+      return -1;
+
+   if ((st1.st_dev == st2.st_dev) && (st1.st_ino == st2.st_ino))
+      return 0;
+   else
+      return 3;
 #else
    /* Otherwise we can't tell */
    return -1;
