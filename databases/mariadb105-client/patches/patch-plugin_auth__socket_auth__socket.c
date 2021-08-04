$NetBSD: patch-plugin_auth__socket_auth__socket.c,v 1.1 2021/08/04 15:52:10 nia Exp $

Add SO_PEERCRED definitions for NetBSD.
https://github.com/MariaDB/server/pull/1884

--- plugin/auth_socket/auth_socket.c.orig	2021-06-18 10:19:11.000000000 +0000
+++ plugin/auth_socket/auth_socket.c
@@ -47,6 +47,13 @@
 #define uid cr_uid
 #define ucred xucred
 
+#elif defined HAVE_UNPCBID
+#include <sys/un.h>
+#define level 0
+#define SO_PEERCRED LOCAL_PEEREID
+#define uid unp_euid
+#define ucred unpcbid
+
 #elif defined HAVE_GETPEERUCRED
 #include <ucred.h>
 
