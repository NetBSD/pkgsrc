$NetBSD: patch-src_unixstream.c,v 1.1 2026/02/26 17:09:47 sborrill Exp $

Use SUN_LEN macro if we have it

--- src/unixstream.c.orig	2026-02-26 16:40:15.320147930 +0000
+++ src/unixstream.c	2026-02-26 16:46:11.527946740 +0000
@@ -190,9 +190,7 @@
     strcpy(local.sun_path, path);
     local.sun_family = AF_UNIX;
 #ifdef UNIX_HAS_SUN_LEN
-    local.sun_len = sizeof(local.sun_family) + sizeof(local.sun_len)
-        + len + 1;
-    err = socket_bind(&un->sock, (SA *) &local, local.sun_len);
+    err = socket_bind(&un->sock, (SA *) &local, SUN_LEN(&local));
 
 #else
     err = socket_bind(&un->sock, (SA *) &local,
@@ -245,9 +243,7 @@
     remote.sun_family = AF_UNIX;
     timeout_markstart(&un->tm);
 #ifdef UNIX_HAS_SUN_LEN
-    remote.sun_len = sizeof(remote.sun_family) + sizeof(remote.sun_len)
-        + len + 1;
-    err = socket_connect(&un->sock, (SA *) &remote, remote.sun_len, &un->tm);
+    err = socket_connect(&un->sock, (SA *) &remote, SUN_LEN(&remote), &un->tm);
 #else
     err = socket_connect(&un->sock, (SA *) &remote,
             sizeof(remote.sun_family) + len, &un->tm);
