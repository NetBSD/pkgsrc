$NetBSD: patch-certbot__nginx___internal_constants.py,v 1.1 2020/06/21 08:00:03 plunky Exp $

Look for nginx.conf in PKG_SYSCONFDIR

--- certbot_nginx/_internal/constants.py.orig	2020-02-04 21:46:57.000000000 +0000
+++ certbot_nginx/_internal/constants.py
@@ -1,8 +1,8 @@
 """nginx plugin constants."""
 import platform
 
-FREEBSD_DARWIN_SERVER_ROOT = "/usr/local/etc/nginx"
-LINUX_SERVER_ROOT = "/etc/nginx"
+FREEBSD_DARWIN_SERVER_ROOT = "@PKG_SYSCONFDIR@/nginx"
+LINUX_SERVER_ROOT = "@PKG_SYSCONFDIR@/nginx"
 
 if platform.system() in ('FreeBSD', 'Darwin'):
     server_root_tmp = FREEBSD_DARWIN_SERVER_ROOT
