$NetBSD: patch-main_pbx__builtins.c,v 1.1 2023/12/10 06:40:20 ryoon Exp $

--- main/pbx_builtins.c.orig	2018-05-01 20:12:26.000000000 +0000
+++ main/pbx_builtins.c
@@ -877,7 +877,7 @@ static int pbx_builtin_gotoiftime(struct
 	struct ast_timing timing;
 	const char *ctime;
 	struct timeval tv = ast_tvnow();
-	long timesecs;
+	int64_t timesecs;
 
 	if (!chan) {
 		ast_log(LOG_WARNING, "GotoIfTime requires a channel on which to operate\n");
@@ -892,8 +892,8 @@ static int pbx_builtin_gotoiftime(struct
 	ts = s = ast_strdupa(data);
 
 	ast_channel_lock(chan);
-	if ((ctime = pbx_builtin_getvar_helper(chan, "TESTTIME")) && sscanf(ctime, "%ld", &timesecs) == 1) {
-		tv.tv_sec = timesecs;
+	if ((ctime = pbx_builtin_getvar_helper(chan, "TESTTIME")) && sscanf(ctime, "%" SCNd64, &timesecs) == 1) {
+		tv.tv_sec = (time_t)timesecs;
 	} else if (ctime) {
 		ast_log(LOG_WARNING, "Using current time to evaluate\n");
 		/* Reset when unparseable */
