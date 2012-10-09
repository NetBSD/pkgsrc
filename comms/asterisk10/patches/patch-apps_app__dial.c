$NetBSD: patch-apps_app__dial.c,v 1.2 2012/10/09 01:36:32 jnemeth Exp $

--- apps/app_dial.c.orig	2012-08-29 18:24:54.000000000 +0000
+++ apps/app_dial.c
@@ -1935,12 +1935,12 @@ static void end_bridge_callback(void *da
 
 	ast_channel_lock(chan);
 	if (chan->cdr->answer.tv_sec) {
-		snprintf(buf, sizeof(buf), "%ld", (long) end - chan->cdr->answer.tv_sec);
+		snprintf(buf, sizeof(buf), "%jd", (intmax_t) ((long) end - chan->cdr->answer.tv_sec));
 		pbx_builtin_setvar_helper(chan, "ANSWEREDTIME", buf);
 	}
 
 	if (chan->cdr->start.tv_sec) {
-		snprintf(buf, sizeof(buf), "%ld", (long) end - chan->cdr->start.tv_sec);
+		snprintf(buf, sizeof(buf), "%jd", (intmax_t) ((long) end - chan->cdr->start.tv_sec));
 		pbx_builtin_setvar_helper(chan, "DIALEDTIME", buf);
 	}
 	ast_channel_unlock(chan);
