$NetBSD: patch-apps_app__chanspy.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- apps/app_chanspy.c.orig	2018-05-07 17:20:13.916423247 +0000
+++ apps/app_chanspy.c
@@ -1105,7 +1105,7 @@ static int common_exec(struct ast_channe
 				if ((ptr = strchr(peer_name, '/'))) {
 					*ptr++ = '\0';
 					for (s = peer_name; s < ptr; s++) {
-						*s = tolower(*s);
+						*s = tolower((unsigned char)*s);
 					}
 					if ((s = strchr(ptr, '-'))) {
 						*s = '\0';
