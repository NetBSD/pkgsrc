$NetBSD: patch-src_ircd.c,v 1.2 2019/05/18 20:34:56 fox Exp $

Properly check for possible fgets(3) errors (otherwise possible
unrelated errors are logged).

--- src/ircd.c.orig	2019-04-24 17:50:27.000000000 +0000
+++ src/ircd.c
@@ -236,8 +236,11 @@ check_pidfile(const char *filename)
   if ((fb = fopen(filename, "r")))
   {
     if (fgets(buf, 20, fb) == NULL)
-      ilog(LOG_TYPE_IRCD, "Error reading from pid file %s: %s",
-           filename, strerror(errno));
+    {
+      if (ferror(fb))
+        ilog(LOG_TYPE_IRCD, "Error reading from pid file %s: %s",
+             filename, strerror(errno));
+    }
     else
     {
       pid_t pid = atoi(buf);
