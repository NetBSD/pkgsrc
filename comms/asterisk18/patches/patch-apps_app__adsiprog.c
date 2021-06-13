$NetBSD: patch-apps_app__adsiprog.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- apps/app_adsiprog.c.orig	2018-05-07 17:17:45.731153122 +0000
+++ apps/app_adsiprog.c
@@ -215,7 +215,7 @@ static int process_token(void *out, char
 			/* Convert */
 			*((unsigned int *)out) = htonl(*((unsigned int *)out));
 		}
-	} else if ((strlen(src) > 2) && (src[0] == '0') && (tolower(src[1]) == 'x')) {
+	} else if ((strlen(src) > 2) && (src[0] == '0') && (tolower((unsigned char)src[1]) == 'x')) {
 		if (!(argtype & ARG_NUMBER))
 			return -1;
 		/* Hex value */
@@ -225,7 +225,7 @@ static int process_token(void *out, char
 			/* Convert */
 			*((unsigned int *)out) = htonl(*((unsigned int *)out));
 		}
-	} else if ((!ast_strlen_zero(src) && isdigit(src[0]))) {
+	} else if ((!ast_strlen_zero(src) && isdigit((unsigned char)src[0]))) {
 		if (!(argtype & ARG_NUMBER))
 			return -1;
 		/* Hex value */
