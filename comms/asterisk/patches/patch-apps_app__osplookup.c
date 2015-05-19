$NetBSD: patch-apps_app__osplookup.c,v 1.1 2015/05/19 07:52:14 jnemeth Exp $

--- apps/app_osplookup.c.orig	2015-05-19 02:25:11.000000000 +0000
+++ apps/app_osplookup.c
@@ -2881,9 +2881,9 @@ static int ospfinished_exec(
 		connect = 0;
 		end = 0;
 	}
-	ast_debug(1, "OSPFinish: start '%ld'\n", start);
-	ast_debug(1, "OSPFinish: connect '%ld'\n", connect);
-	ast_debug(1, "OSPFinish: end '%ld'\n", end);
+	ast_debug(1, "OSPFinish: start '%jd'\n", (intmax_t)start);
+	ast_debug(1, "OSPFinish: connect '%jd'\n", (intmax_t)connect);
+	ast_debug(1, "OSPFinish: end '%jd'\n", (intmax_t)end);
 
 	release = ast_check_hangup(chan) ? 0 : 1;
 
