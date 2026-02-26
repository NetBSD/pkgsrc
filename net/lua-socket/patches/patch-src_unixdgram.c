$NetBSD: patch-src_unixdgram.c,v 1.1 2026/02/26 17:09:47 sborrill Exp $

Use SUN_LEN macro if we have it

--- src/unixdgram.c.orig	2026-02-26 16:40:26.691051280 +0000
+++ src/unixdgram.c	2026-02-26 16:42:49.549449941 +0000
@@ -152,9 +152,7 @@
     remote.sun_family = AF_UNIX;
     timeout_markstart(tm);
 #ifdef UNIX_HAS_SUN_LEN
-    remote.sun_len = sizeof(remote.sun_family) + sizeof(remote.sun_len)
-        + len + 1;
-    err = socket_sendto(&un->sock, data, count, &sent, (SA *) &remote, remote.sun_len, tm);
+    err = socket_sendto(&un->sock, data, count, &sent, (SA *) &remote, SUN_LEN(&remote), tm);
 #else
     err = socket_sendto(&un->sock, data, count, &sent, (SA *) &remote,
 		   	sizeof(remote.sun_family) + len, tm);
@@ -273,7 +271,7 @@
     local.sun_family = AF_UNIX;
     size_t addrlen = SUN_LEN(&local);
 #ifdef UNIX_HAS_SUN_LEN
-    local.sun_len = addrlen + 1;
+/*    local.sun_len = addrlen + 1;*/
 #endif
     int err = socket_bind(&un->sock, (SA *) &local, addrlen);
     if (err != IO_DONE) socket_destroy(&un->sock);
@@ -324,7 +322,7 @@
     timeout_markstart(&un->tm);
     size_t addrlen = SUN_LEN(&remote);
 #ifdef UNIX_HAS_SUN_LEN
-    remote.sun_len = addrlen + 1;
+/*    remote.sun_len = addrlen + 1;*/
 #endif
     int err = socket_connect(&un->sock, (SA *) &remote, addrlen, &un->tm);
     if (err != IO_DONE) socket_destroy(&un->sock);
