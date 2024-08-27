$NetBSD: patch-src_gam_var.py,v 1.1 2024/08/27 16:04:44 sborrill Exp $

Use roots.pem from grpc

--- gam/var.py.orig	2024-08-27 16:22:42.815476055 +0100
+++ gam/var.py	2024-08-27 16:30:07.436182070 +0100
@@ -1249,7 +1249,7 @@
 _FN_CLIENT_SECRETS_JSON = 'client_secrets.json'
 _FN_OAUTH2SERVICE_JSON = 'oauth2service.json'
 _FN_OAUTH2_TXT = 'oauth2.txt'
-_FN_ROOTS_PEM = 'roots.pem'
+_FN_ROOTS_PEM = '@LOCALBASE@/share/grpc/roots.pem'
 #
 GM_Globals = {
     GM_SYSEXITRC: 0,
