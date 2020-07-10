$NetBSD: patch-certbot__nginx___internal_constants.py,v 1.2 2020/07/10 10:24:23 adam Exp $

Look for nginx.conf in PKG_SYSCONFDIR

--- certbot_nginx/_internal/constants.py.orig	2020-07-07 17:13:20.000000000 +0000
+++ certbot_nginx/_internal/constants.py
@@ -1,19 +1,8 @@
 """nginx plugin constants."""
 import platform
 
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
 )
 """CLI defaults."""
