$NetBSD: patch-apps_app__followme.c,v 1.1.1.1 2016/10/25 08:17:05 jnemeth Exp $

--- apps/app_followme.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ apps/app_followme.c
@@ -380,7 +380,7 @@ static struct number *create_followme_nu
 		*tmp = '\0';
 	ast_copy_string(cur->number, buf, sizeof(cur->number));
 	cur->order = numorder;
-	ast_debug(1, "Created a number, %s, order of , %d, with a timeout of %ld.\n", cur->number, cur->order, cur->timeout);
+	ast_debug(1, "Created a number, %s, order of , %d, with a timeout of %jd.\n", cur->number, cur->order, (intmax_t)cur->timeout);
 
 	return cur;
 }
@@ -1010,7 +1010,7 @@ static struct ast_channel *findmeexec(st
 			break;
 		}
 
-		ast_debug(2, "Number(s) %s timeout %ld\n", nm->number, nm->timeout);
+		ast_debug(2, "Number(s) %s timeout %jd\n", nm->number, (intmax_t)nm->timeout);
 
 		/*
 		 * Put all active outgoing channels into autoservice.
