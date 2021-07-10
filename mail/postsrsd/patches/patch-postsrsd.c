$NetBSD: patch-postsrsd.c,v 1.1 2021/07/10 08:41:56 spz Exp $

make sure we can use a connection more than once
it'll work without the patch but with many error messages in the log

--- postsrsd.c.orig	2021-03-21 19:23:39.000000000 +0000
+++ postsrsd.c	2021-07-09 10:29:40.996255562 +0000
@@ -644,7 +644,7 @@
     }
     while (TRUE)
     {
-        int conn;
+        int conn, flags;
         FILE *fp_read, *fp_write;
         char linebuf[1024], *line;
         char keybuf[1024], *key;
@@ -667,6 +667,16 @@
                 conn = accept(fds[sc].fd, NULL, NULL);
                 if (conn < 0)
                     continue;
+                /* remove the nonblocking for !Linux */
+                flags = fcntl(conn, F_GETFL, 0);
+                if (flags < 0) {
+                    close(conn);
+                    continue;
+                }
+                if (fcntl(conn, F_SETFL, flags & ~O_NONBLOCK) < 0) {
+                    close(conn);
+                    continue;
+                }
                 if (fork() == 0)
                 {
                     int i;
