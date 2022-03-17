$NetBSD: patch-certbot__nginx___internal_constants.py,v 1.5 2022/03/17 12:23:33 adam Exp $

Look for nginx.conf in PKG_SYSCONFDIR

--- certbot_nginx/_internal/constants.py.orig	2022-03-16 18:16:28.000000000 +0000
+++ certbot_nginx/_internal/constants.py
@@ -3,19 +3,8 @@ import platform
 from typing import Any
 from typing import Dict
 
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
 CLI_DEFAULTS: Dict[str, Any] = {
-    "server_root": server_root_tmp,
+    "server_root": "@PKG_SYSCONFDIR@/nginx",
     "ctl": "nginx",
     "sleep_seconds": 1
 }
