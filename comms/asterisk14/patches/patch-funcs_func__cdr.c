$NetBSD: patch-funcs_func__cdr.c,v 1.1.1.1 2016/10/25 08:17:07 jnemeth Exp $

--- funcs/func_cdr.c.orig	2016-09-30 20:36:17.000000000 +0000
+++ funcs/func_cdr.c
@@ -234,7 +234,7 @@ static struct timeval cdr_retrieve_time(
 		ast_cdr_getvar(ast_channel_name(chan), time_name, tempbuf, sizeof(tempbuf));
 	}
 
-	if (sscanf(tempbuf, "%ld.%ld", &time.tv_sec, &time.tv_usec) != 2) {
+	if (sscanf(tempbuf, "%jd.%d", (intmax_t *)&time.tv_sec, &time.tv_usec) != 2) {
 		ast_log(AST_LOG_WARNING, "Failed to fully extract '%s' from CDR\n", time_name);
 	}
 
