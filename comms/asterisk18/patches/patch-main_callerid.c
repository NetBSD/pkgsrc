$NetBSD: patch-main_callerid.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- main/callerid.c.orig	2018-05-07 17:25:23.439816235 +0000
+++ main/callerid.c
@@ -233,20 +233,20 @@ void callerid_get_dtmf(char *cidstring, 
 		for (i = 1; i < strlen(cidstring); i++) {
 			if (cidstring[i] == 'C' || cidstring[i] == '#')
 				break;
-			if (isdigit(cidstring[i]))
+			if (isdigit((unsigned char)cidstring[i]))
 				number[i-1] = cidstring[i];
 			else
 				ast_debug(1, "Unknown CID digit '%c'\n",
 					cidstring[i]);
 		}
 		number[i-1] = 0;
-	} else if (isdigit(cidstring[0])) {
+	} else if (isdigit((unsigned char)cidstring[0])) {
 		/* It begins with a digit, so we parse it as a number and hope
 		 * for the best */
 		ast_log(LOG_WARNING, "Couldn't detect start-character. CID "
 			"parsing might be unreliable\n");
 		for (i = 0; i < strlen(cidstring); i++) {
-			if (isdigit(cidstring[i]))
+			if (isdigit((unsigned char)cidstring[i]))
 				number[i] = cidstring[i];
 			else
 				break;
