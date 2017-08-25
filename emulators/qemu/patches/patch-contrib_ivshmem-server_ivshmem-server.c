$NetBSD: patch-contrib_ivshmem-server_ivshmem-server.c,v 1.1 2017/08/25 12:39:56 jperkin Exp $

Avoid sun definition.

--- contrib/ivshmem-server/ivshmem-server.c.orig	2017-04-20 14:57:00.000000000 +0000
+++ contrib/ivshmem-server/ivshmem-server.c
@@ -289,7 +289,7 @@ ivshmem_server_init(IvshmemServer *serve
 int
 ivshmem_server_start(IvshmemServer *server)
 {
-    struct sockaddr_un sun;
+    struct sockaddr_un sockun;
     int shm_fd, sock_fd, ret;
 
     /* open shm file */
@@ -328,15 +328,15 @@ ivshmem_server_start(IvshmemServer *serv
         goto err_close_shm;
     }
 
-    sun.sun_family = AF_UNIX;
-    ret = snprintf(sun.sun_path, sizeof(sun.sun_path), "%s",
+    sockun.sun_family = AF_UNIX;
+    ret = snprintf(sockun.sun_path, sizeof(sockun.sun_path), "%s",
                    server->unix_sock_path);
-    if (ret < 0 || ret >= sizeof(sun.sun_path)) {
+    if (ret < 0 || ret >= sizeof(sockun.sun_path)) {
         IVSHMEM_SERVER_DEBUG(server, "could not copy unix socket path\n");
         goto err_close_sock;
     }
-    if (bind(sock_fd, (struct sockaddr *)&sun, sizeof(sun)) < 0) {
-        IVSHMEM_SERVER_DEBUG(server, "cannot connect to %s: %s\n", sun.sun_path,
+    if (bind(sock_fd, (struct sockaddr *)&sockun, sizeof(sockun)) < 0) {
+        IVSHMEM_SERVER_DEBUG(server, "cannot connect to %s: %s\n", sockun.sun_path,
                              strerror(errno));
         goto err_close_sock;
     }
