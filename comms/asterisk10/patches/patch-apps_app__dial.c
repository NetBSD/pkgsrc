$NetBSD: patch-apps_app__dial.c,v 1.1.1.1 2012/01/15 18:36:21 jnemeth Exp $

--- apps/app_dial.c.orig	2011-10-05 17:01:46.000000000 +0000
+++ apps/app_dial.c
@@ -1816,12 +1816,12 @@ static void end_bridge_callback(void *da
 
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
