$NetBSD: patch-apps_app__followme.c,v 1.2 2012/10/09 01:36:32 jnemeth Exp $

--- apps/app_followme.c.orig	2012-09-06 00:56:47.000000000 +0000
+++ apps/app_followme.c
@@ -1127,12 +1127,12 @@ static void end_bridge_callback(void *da
 
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
