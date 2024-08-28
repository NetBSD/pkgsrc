$NetBSD: patch-src_gam_var.py,v 1.2 2024/08/28 13:20:34 sborrill Exp $

Use roots.pem from grpc.
Place generated authentication token into PKG_SYSCONFDIR/gam

--- gam/var.py.orig	2024-08-27 16:22:42.815476055 +0100
+++ gam/var.py	2024-08-27 16:30:07.436182070 +0100
@@ -1246,10 +1246,10 @@
 
 #
 _DEFAULT_CHARSET = UTF8
-_FN_CLIENT_SECRETS_JSON = 'client_secrets.json'
-_FN_OAUTH2SERVICE_JSON = 'oauth2service.json'
-_FN_OAUTH2_TXT = 'oauth2.txt'
-_FN_ROOTS_PEM = 'roots.pem'
+_FN_CLIENT_SECRETS_JSON = '@PKG_SYSCONFDIR@/client_secrets.json'
+_FN_OAUTH2SERVICE_JSON = '@PKG_SYSCONFDIR@/oauth2service.json'
+_FN_OAUTH2_TXT = '@PKG_SYSCONFDIR@/oauth2.txt'
+_FN_ROOTS_PEM = '@LOCALBASE@/share/grpc/roots.pem'
 #
 GM_Globals = {
     GM_SYSEXITRC: 0,
