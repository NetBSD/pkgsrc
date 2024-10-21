$NetBSD: patch-main_pbx__builtins.c,v 1.1 2024/10/21 05:12:47 jnemeth Exp $

--- main/pbx_builtins.c.orig	2024-01-25 16:23:00.000000000 +0000
+++ main/pbx_builtins.c
@@ -898,7 +898,7 @@ static int pbx_builtin_gotoiftime(struct
 	struct ast_timing timing;
 	const char *ctime;
 	struct timeval tv = ast_tvnow();
-	long timesecs;
+	int64_t timesecs;
 
 	if (!chan) {
 		ast_log(LOG_WARNING, "GotoIfTime requires a channel on which to operate\n");
@@ -913,8 +913,8 @@ static int pbx_builtin_gotoiftime(struct
 	ts = s = ast_strdupa(data);
 
 	ast_channel_lock(chan);
-	if ((ctime = pbx_builtin_getvar_helper(chan, "TESTTIME")) && sscanf(ctime, "%ld", &timesecs) == 1) {
-		tv.tv_sec = timesecs;
+	if ((ctime = pbx_builtin_getvar_helper(chan, "TESTTIME")) && sscanf(ctime, "%" SCNd64, &timesecs) == 1) {
+		tv.tv_sec = (time_t)timesecs;
 	} else if (ctime) {
 		ast_log(LOG_WARNING, "Using current time to evaluate\n");
 		/* Reset when unparseable */
