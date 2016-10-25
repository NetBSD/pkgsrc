$NetBSD: patch-main_pbx.c,v 1.1.1.1 2016/10/25 08:17:07 jnemeth Exp $

--- main/pbx.c.orig	2016-04-20 10:46:18.000000000 +0000
+++ main/pbx.c
@@ -7973,7 +7973,7 @@ static int testtime_write(struct ast_cha
 	sscanf(remainder, "%79s", timezone);
 	tv = ast_mktime(&tm, S_OR(timezone, NULL));
 
-	snprintf(result, sizeof(result), "%ld", (long) tv.tv_sec);
+	snprintf(result, sizeof(result), "%jd", (intmax_t) tv.tv_sec);
 	pbx_builtin_setvar_helper(chan, "__TESTTIME", result);
 	return 0;
 }
