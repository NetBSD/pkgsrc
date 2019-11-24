$NetBSD: patch-web_history.c,v 1.1 2019/11/24 20:16:55 spz Exp $

from https://sourceforge.net/p/xymon/code/8072/
Fix reports with dashes or underscores not visible in history logs (Thanks, Tom Schmidt)

--- web/history.c.orig	2019-07-23 14:46:51.000000000 +0000
+++ web/history.c
@@ -605,7 +605,7 @@ static void parse_query(void)
 		 */
 
 		if (strcasecmp(cwalk->name, "HISTFILE") == 0) {
-			char *p = cwalk->value + strspn(cwalk->value, "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789.,");
+			char *p = cwalk->value + strspn(cwalk->value, "abcdefghijklmnopqrstuvwxyz0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ:,.\\/_-");
 			*p = '\0';
 
 			p = strrchr(cwalk->value, '.');
