$NetBSD: patch-certbot__nginx___internal_constants.py,v 1.3 2020/08/26 11:10:15 adam Exp $

Look for nginx.conf in PKG_SYSCONFDIR

--- certbot_nginx/_internal/constants.py.orig	2020-08-04 18:20:15.000000000 +0000
+++ certbot_nginx/_internal/constants.py
@@ -4,19 +4,8 @@ import platform
 from acme.magic_typing import Any
 from acme.magic_typing import Dict
 
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
 CLI_DEFAULTS = dict(
-    server_root=server_root_tmp,
+    server_root="@PKG_SYSCONFDIR@/nginx",
     ctl="nginx",
     sleep_seconds=1
 ) # type: Dict[str, Any]
