$NetBSD: patch-backend_pixma_pixma__bjnp.c,v 1.1 2020/06/13 20:54:32 leot Exp $

Reuse BJNP_HOST_MAX instead of possible undefined HOST_NAME_MAX.

scanner_host is populated via get_scanner_name() that is already
limited by BJNP_HOST_MAX.

--- backend/pixma/pixma_bjnp.c.orig	2020-05-17 11:54:18.000000000 +0000
+++ backend/pixma/pixma_bjnp.c
@@ -1990,8 +1990,8 @@ sanei_bjnp_find_devices (const char **co
   fd_set fdset;
   fd_set active_fdset;
   struct timeval timeout;
-  char scanner_host[HOST_NAME_MAX];
-  char uri[HOST_NAME_MAX + 32];
+  char scanner_host[BJNP_HOST_MAX];
+  char uri[BJNP_HOST_MAX + 32];
   int dev_no;
   int port;
   int auto_detect = 1;
