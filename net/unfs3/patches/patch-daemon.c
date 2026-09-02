$NetBSD: patch-daemon.c,v 1.1 2026/09/02 18:47:29 maya Exp $

Use getsockname for NetBSD

--- daemon.c.orig	2025-03-28 08:56:00.000000000 +0000
+++ daemon.c
@@ -707,7 +707,15 @@ static void mountprog_3(struct svc_req *
 static int
 _socket_getdomain(int socket)
 {
-#ifdef SO_DOMAIN
+#if defined(__NetBSD__)
+    struct sockaddr name;
+    socklen_t namelen = sizeof(name);
+
+    if (getsockname(socket, &name, &namelen) == -1)
+        return -1;
+
+    return name.sa_family;
+#elif defined(SO_DOMAIN)
     int ret, domain;
     socklen_t len;
     len = sizeof(domain);
