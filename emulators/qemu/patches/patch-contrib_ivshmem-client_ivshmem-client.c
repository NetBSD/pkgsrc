$NetBSD: patch-contrib_ivshmem-client_ivshmem-client.c,v 1.1 2017/08/25 12:39:56 jperkin Exp $

Avoid sun definition.

--- contrib/ivshmem-client/ivshmem-client.c.orig	2017-04-20 14:57:00.000000000 +0000
+++ contrib/ivshmem-client/ivshmem-client.c
@@ -179,7 +179,7 @@ ivshmem_client_init(IvshmemClient *clien
 int
 ivshmem_client_connect(IvshmemClient *client)
 {
-    struct sockaddr_un sun;
+    struct sockaddr_un sockun;
     int fd, ret;
     int64_t tmp;
 
@@ -193,16 +193,16 @@ ivshmem_client_connect(IvshmemClient *cl
         return -1;
     }
 
-    sun.sun_family = AF_UNIX;
-    ret = snprintf(sun.sun_path, sizeof(sun.sun_path), "%s",
+    sockun.sun_family = AF_UNIX;
+    ret = snprintf(sockun.sun_path, sizeof(sockun.sun_path), "%s",
                    client->unix_sock_path);
-    if (ret < 0 || ret >= sizeof(sun.sun_path)) {
+    if (ret < 0 || ret >= sizeof(sockun.sun_path)) {
         IVSHMEM_CLIENT_DEBUG(client, "could not copy unix socket path\n");
         goto err_close;
     }
 
-    if (connect(client->sock_fd, (struct sockaddr *)&sun, sizeof(sun)) < 0) {
-        IVSHMEM_CLIENT_DEBUG(client, "cannot connect to %s: %s\n", sun.sun_path,
+    if (connect(client->sock_fd, (struct sockaddr *)&sockun, sizeof(sockun)) < 0) {
+        IVSHMEM_CLIENT_DEBUG(client, "cannot connect to %s: %s\n", sockun.sun_path,
                              strerror(errno));
         goto err_close;
     }
