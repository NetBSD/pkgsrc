$NetBSD: patch-svr-session.c,v 1.1 2023/12/20 17:09:36 wiz Exp $

Terrapin fix
https://github.com/mkj/dropbear/commit/6e43be5c7b99dbee49dc72b6f989f29fdd7e9356

--- svr-session.c.orig	2022-11-14 14:30:00.000000000 +0000
+++ svr-session.c
@@ -370,6 +370,9 @@ static void svr_algos_initialise(void) {
 			algo->usable = 0;
 		}
 #endif
+		if (strcmp(algo->name, SSH_STRICT_KEX_C) == 0) {
+			algo->usable = 0;
+		}
 	}
 }
 
