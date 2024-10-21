$NetBSD: patch-res_res__pjsip__diversion.c,v 1.1 2024/10/21 05:12:48 jnemeth Exp $

--- res/res_pjsip_diversion.c.orig	2022-04-14 22:16:42.000000000 +0000
+++ res/res_pjsip_diversion.c
@@ -61,7 +61,7 @@ static int sip_is_token(const char *str)
 
 	is_token = 1;
 	do {
-		if (!isalnum(*str)
+		if (!isalnum((unsigned char)*str)
 			&& !strchr("-.!%*_+`'~", *str)) {
 			/* The character is not allowed in a token. */
 			is_token = 0;
