$NetBSD: patch-main_pbx.c,v 1.1 2015/05/19 07:52:14 jnemeth Exp $

--- main/pbx.c.orig	2015-01-30 16:55:39.000000000 +0000
+++ main/pbx.c
@@ -11201,7 +11201,7 @@ static int testtime_write(struct ast_cha
 	sscanf(remainder, "%79s", timezone);
 	tv = ast_mktime(&tm, S_OR(timezone, NULL));
 
-	snprintf(result, sizeof(result), "%ld", (long) tv.tv_sec);
+	snprintf(result, sizeof(result), "%jd", (intmax_t) tv.tv_sec);
 	pbx_builtin_setvar_helper(chan, "__TESTTIME", result);
 	return 0;
 }
@@ -11235,7 +11235,7 @@ static int pbx_builtin_gotoiftime(struct
 	ts = s = ast_strdupa(data);
 
 	ast_channel_lock(chan);
-	if ((ctime = pbx_builtin_getvar_helper(chan, "TESTTIME")) && sscanf(ctime, "%ld", &timesecs) == 1) {
+	if ((ctime = pbx_builtin_getvar_helper(chan, "TESTTIME")) && sscanf(ctime, "%jd", &timesecs) == 1) {
 		tv.tv_sec = timesecs;
 	} else if (ctime) {
 		ast_log(LOG_WARNING, "Using current time to evaluate\n");
