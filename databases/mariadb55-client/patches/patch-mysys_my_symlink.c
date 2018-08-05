$NetBSD: patch-mysys_my_symlink.c,v 1.1 2018/08/05 15:59:26 manu Exp $

Fix server startup failure on NetBSD. From upstream
https://github.com/MariaDB/server/pull/838

--- mysys/my_symlink.c.orig	2018-08-05 09:34:34.048086306 +0000
+++ mysys/my_symlink.c	2018-08-05 12:19:23.894217529 +0000
@@ -235,9 +236,22 @@
       *pdfd= dfd;
       return pathname + (s - buf);
     }
 
-    fd = openat(dfd, s, O_NOFOLLOW | O_PATH);
+    /*
+     * Linux accepts dfd = -1 for root, but this is not a standard
+     * behavior documented by OpenGroup XSH
+     * http://pubs.opengroup.org/onlinepubs/9699919799/functions/open.html
+     * At least on NetBSD, calling openat() with dfd = -1 fails with EBADF.
+     * Since s has been tested to be an absolute parth, just use open()
+     * on non Linux systems for the same result.
+     */
+#ifndef linux
+    if (dfd == -1)
+      fd = open(s, O_NOFOLLOW | O_PATH);
+    else
+#endif
+      fd = openat(dfd, s, O_NOFOLLOW | O_PATH);
     if (fd < 0)
       goto err;
 
     if (dfd >= 0)
