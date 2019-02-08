$NetBSD: patch-src_ircd.c,v 1.1 2019/02/08 13:09:35 fox Exp $

Properly check for possible fgets(3) errors (otherwise possible
unrelated errors are logged).

--- src/ircd.c.orig	2018-04-04 22:33:37.000000000 +0000
+++ src/ircd.c
@@ -265,8 +265,11 @@ check_pidfile(const char *filename)
   if ((fb = fopen(filename, "r")))
   {
     if (!fgets(buf, 20, fb))
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
