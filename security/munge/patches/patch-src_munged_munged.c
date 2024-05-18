$NetBSD: patch-src_munged_munged.c,v 1.1 2024/05/18 22:31:06 bacon Exp $

# Use local strlcpy() without collision

--- src/munged/munged.c.orig	2024-05-18 22:06:54.452854855 +0000
+++ src/munged/munged.c
@@ -653,7 +653,7 @@ sock_create (conf_t conf)
     }
     memset (&addr, 0, sizeof (addr));
     addr.sun_family = AF_UNIX;
-    n = strlcpy (addr.sun_path, conf->socket_name, sizeof (addr.sun_path));
+    n = __munge_strlcpy (addr.sun_path, conf->socket_name, sizeof (addr.sun_path));
     if (n >= sizeof (addr.sun_path)) {
         log_err (EMUNGE_SNAFU, LOG_ERR,
             "Exceeded maximum length of %lu bytes for socket pathname",
