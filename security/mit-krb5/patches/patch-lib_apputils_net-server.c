$NetBSD: patch-lib_apputils_net-server.c,v 1.5 2026/04/10 10:38:05 jperkin Exp $

Avoid sun conflict.

--- lib/apputils/net-server.c.orig	2026-04-10 10:21:02.105019528 +0000
+++ lib/apputils/net-server.c
@@ -938,7 +938,7 @@ setup_addresses(verto_ctx *ctx, void *ha
     size_t i;
     int err, bound_any;
     struct bind_address addr;
-    struct sockaddr_un sun;
+    struct sockaddr_un sockun;
     struct addrinfo hints, *ai_list = NULL, *ai = NULL;
     struct sockact_list sockacts = { 0 };
     verto_callback vcb;
@@ -967,16 +967,16 @@ setup_addresses(verto_ctx *ctx, void *ha
         hints.ai_socktype = bind_socktypes[addr.type];
 
         if (addr.type == UNX) {
-            sun.sun_family = AF_UNIX;
-            if (strlcpy(sun.sun_path, addr.address, sizeof(sun.sun_path)) >=
-                sizeof(sun.sun_path)) {
+            sockun.sun_family = AF_UNIX;
+            if (strlcpy(sockun.sun_path, addr.address, sizeof(sockun.sun_path)) >=
+                sizeof(sockun.sun_path)) {
                 ret = ENAMETOOLONG;
                 krb5_klog_syslog(LOG_ERR,
                                  _("UNIX domain socket path too long: %s"),
                                  addr.address);
                 goto cleanup;
             }
-            ret = setup_socket(&addr, (struct sockaddr *)&sun, &sockacts,
+            ret = setup_socket(&addr, (struct sockaddr *)&sockun, &sockacts,
                                handle, prog, ctx, listen_backlog,
                                verto_callbacks[addr.type],
                                bind_conn_types[addr.type]);
