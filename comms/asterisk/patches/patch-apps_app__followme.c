$NetBSD: patch-apps_app__followme.c,v 1.1 2012/12/11 08:22:48 jnemeth Exp $

--- apps/app_followme.c.orig	2012-09-06 00:59:23.000000000 +0000
+++ apps/app_followme.c
@@ -1284,12 +1284,12 @@ static void end_bridge_callback(void *da
 
 	ast_channel_lock(chan);
 	if (ast_channel_cdr(chan)->answer.tv_sec) {
-		snprintf(buf, sizeof(buf), "%ld", (long) end - ast_channel_cdr(chan)->answer.tv_sec);
+		snprintf(buf, sizeof(buf), "%jd", (intmax_t) end - ast_channel_cdr(chan)->answer.tv_sec);
 		pbx_builtin_setvar_helper(chan, "ANSWEREDTIME", buf);
 	}
 
 	if (ast_channel_cdr(chan)->start.tv_sec) {
-		snprintf(buf, sizeof(buf), "%ld", (long) end - ast_channel_cdr(chan)->start.tv_sec);
+		snprintf(buf, sizeof(buf), "%jd", (intmax_t) end - ast_channel_cdr(chan)->start.tv_sec);
 		pbx_builtin_setvar_helper(chan, "DIALEDTIME", buf);
 	}
 	ast_channel_unlock(chan);
