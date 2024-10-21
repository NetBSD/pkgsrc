$NetBSD: patch-apps_app__minivm.c,v 1.1 2024/10/21 05:12:45 jnemeth Exp $

--- apps/app_minivm.c.orig	2018-05-07 17:45:03.072823223 +0000
+++ apps/app_minivm.c
@@ -1593,7 +1593,7 @@ static int invent_message(struct ast_cha
 
 		while (*i)  {
 			ast_debug(2, "Numeric? Checking %c\n", *i);
-			if (!isdigit(*i)) {
+			if (!isdigit((unsigned char)*i)) {
 				numericusername = FALSE;
 				break;
 			}
