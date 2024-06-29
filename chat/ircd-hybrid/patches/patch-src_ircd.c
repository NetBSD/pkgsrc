$NetBSD: patch-src_ircd.c,v 1.3 2024/06/29 01:10:14 fox Exp $

Properly check for possible fgets(3) errors (otherwise possible
unrelated errors are logged).

--- src/ircd.c.orig	2024-06-15 10:35:58.000000000 +0000
+++ src/ircd.c
@@ -347,8 +347,11 @@ check_pidfile(const char *filename)
     char buf[IRCD_BUFSIZE];
 
     if (fgets(buf, 20, fb) == NULL)
-      log_write(LOG_TYPE_IRCD, "Error reading from pid file %s: %s",
-                filename, strerror(errno));
+    {
+      if (ferror(fb))
+        log_write(LOG_TYPE_IRCD, "Error reading from pid file %s: %s",
+             filename, strerror(errno));
+    }      
     else
     {
       pid_t pid = atoi(buf);
