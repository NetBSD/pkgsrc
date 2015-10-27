$NetBSD: patch-main_pbx.c,v 1.2 2015/10/27 08:49:01 jnemeth Exp $

--- main/pbx.c.orig	2015-10-09 22:23:39.000000000 +0000
+++ main/pbx.c
@@ -11427,7 +11427,7 @@ static int testtime_write(struct ast_cha
 	sscanf(remainder, "%79s", timezone);
 	tv = ast_mktime(&tm, S_OR(timezone, NULL));
 
-	snprintf(result, sizeof(result), "%ld", (long) tv.tv_sec);
+	snprintf(result, sizeof(result), "%jd", (intmax_t) tv.tv_sec);
 	pbx_builtin_setvar_helper(chan, "__TESTTIME", result);
 	return 0;
 }
@@ -11446,7 +11446,7 @@ static int pbx_builtin_gotoiftime(struct
 	struct ast_timing timing;
 	const char *ctime;
 	struct timeval tv = ast_tvnow();
-	long timesecs;
+	intmax_t timesecs;
 
 	if (!chan) {
 		ast_log(LOG_WARNING, "GotoIfTime requires a channel on which to operate\n");
@@ -11461,7 +11461,7 @@ static int pbx_builtin_gotoiftime(struct
 	ts = s = ast_strdupa(data);
 
 	ast_channel_lock(chan);
-	if ((ctime = pbx_builtin_getvar_helper(chan, "TESTTIME")) && sscanf(ctime, "%ld", &timesecs) == 1) {
+	if ((ctime = pbx_builtin_getvar_helper(chan, "TESTTIME")) && sscanf(ctime, "%jd", &timesecs) == 1) {
 		tv.tv_sec = timesecs;
 	} else if (ctime) {
 		ast_log(LOG_WARNING, "Using current time to evaluate\n");
