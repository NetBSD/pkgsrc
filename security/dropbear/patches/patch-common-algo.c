$NetBSD: patch-common-algo.c,v 1.1 2023/12/20 17:09:36 wiz Exp $

Terrapin fix
https://github.com/mkj/dropbear/commit/6e43be5c7b99dbee49dc72b6f989f29fdd7e9356

--- common-algo.c.orig	2022-11-14 14:30:00.000000000 +0000
+++ common-algo.c
@@ -308,6 +308,12 @@ algo_type sshkex[] = {
 	{SSH_EXT_INFO_C, 0, NULL, 1, NULL},
 #endif
 #endif
+#if DROPBEAR_CLIENT
+	{SSH_STRICT_KEX_C, 0, NULL, 1, NULL},
+#endif
+#if DROPBEAR_SERVER
+	{SSH_STRICT_KEX_S, 0, NULL, 1, NULL},
+#endif
 	{NULL, 0, NULL, 0, NULL}
 };
 
