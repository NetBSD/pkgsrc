$NetBSD: patch-src_certbot__nginx___internal_constants.py,v 1.2 2025/09/15 11:16:02 adam Exp $

Look for nginx.conf in PKG_SYSCONFDIR

--- src/certbot_nginx/_internal/constants.py.orig	2025-09-02 15:46:13.000000000 +0000
+++ src/certbot_nginx/_internal/constants.py
@@ -2,19 +2,8 @@
 import platform
 from typing import Any
 
-FREEBSD_DARWIN_SERVER_ROOT = "/usr/local/etc/nginx"
-LINUX_SERVER_ROOT = "/etc/nginx"
-PKGSRC_SERVER_ROOT = "/usr/pkg/etc/nginx"
-
-if platform.system() in ('FreeBSD', 'Darwin'):
-    server_root_tmp = FREEBSD_DARWIN_SERVER_ROOT
-elif platform.system() in ('NetBSD',):
-    server_root_tmp = PKGSRC_SERVER_ROOT
-else:
-    server_root_tmp = LINUX_SERVER_ROOT
-
 CLI_DEFAULTS: dict[str, Any] = {
-    "server_root": server_root_tmp,
+    "server_root": "@PKG_SYSCONFDIR@/nginx",
     "ctl": "nginx",
     "sleep_seconds": 1
 }
