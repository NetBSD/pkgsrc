$NetBSD: patch-pkcs11_rpc-layer_gkm-rpc-module.c,v 1.1 2020/11/22 21:26:51 nia Exp $

Argument to ctype functions must be unsigned char.

--- pkcs11/rpc-layer/gkm-rpc-module.c.orig	2018-06-25 04:15:03.000000000 +0000
+++ pkcs11/rpc-layer/gkm-rpc-module.c
@@ -143,7 +143,7 @@ parse_arguments (const char *string)
 			*at++ = *src;
 
 		/* Space, not inside of quotes */
-		} else if (isspace(*src)) {
+		} else if (isspace((unsigned char)*src)) {
 			*at = 0;
 			parse_argument (arg);
 			arg = at;
