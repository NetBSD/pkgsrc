$NetBSD: patch-ssh.h,v 1.1 2023/12/20 17:09:36 wiz Exp $

Terrapin fix
https://github.com/mkj/dropbear/commit/6e43be5c7b99dbee49dc72b6f989f29fdd7e9356

--- ssh.h.orig	2022-11-14 14:30:00.000000000 +0000
+++ ssh.h
@@ -100,6 +100,10 @@
 #define SSH_EXT_INFO_C "ext-info-c"
 #define SSH_SERVER_SIG_ALGS "server-sig-algs"
 
+/* OpenSSH strict KEX feature */
+#define SSH_STRICT_KEX_S "kex-strict-s-v00@openssh.com"
+#define SSH_STRICT_KEX_C "kex-strict-c-v00@openssh.com"
+
 /* service types */
 #define SSH_SERVICE_USERAUTH "ssh-userauth"
 #define SSH_SERVICE_USERAUTH_LEN 12
