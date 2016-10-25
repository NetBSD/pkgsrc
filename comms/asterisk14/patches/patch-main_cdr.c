$NetBSD: patch-main_cdr.c,v 1.1.1.1 2016/10/25 08:17:05 jnemeth Exp $

--- main/cdr.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ main/cdr.c
@@ -2787,7 +2787,7 @@ static const char *cdr_format_var_intern
 static void cdr_get_tv(struct timeval when, const char *fmt, char *buf, int bufsize)
 {
 	if (fmt == NULL) {	/* raw mode */
-		snprintf(buf, bufsize, "%ld.%06ld", (long)when.tv_sec, (long)when.tv_usec);
+		snprintf(buf, bufsize, "%jd.%06ld", (intmax_t)when.tv_sec, (long)when.tv_usec);
 	} else {
 		buf[0] = '\0';/* Ensure the buffer is initialized. */
 		if (when.tv_sec) {
@@ -2833,9 +2833,9 @@ void ast_cdr_format_var(struct ast_cdr *
 	} else if (!strcasecmp(name, "end")) {
 		cdr_get_tv(cdr->end, raw ? NULL : fmt, workspace, workspacelen);
 	} else if (!strcasecmp(name, "duration")) {
-		snprintf(workspace, workspacelen, "%ld", cdr->end.tv_sec != 0 ? cdr->duration : (long)ast_tvdiff_ms(ast_tvnow(), cdr->start) / 1000);
+		snprintf(workspace, workspacelen, "%jd", cdr->end.tv_sec != 0 ? cdr->duration : (intmax_t)ast_tvdiff_ms(ast_tvnow(), cdr->start) / 1000);
 	} else if (!strcasecmp(name, "billsec")) {
-		snprintf(workspace, workspacelen, "%ld", (cdr->billsec || !ast_tvzero(cdr->end) || ast_tvzero(cdr->answer)) ? cdr->billsec : (long)ast_tvdiff_ms(ast_tvnow(), cdr->answer) / 1000);
+		snprintf(workspace, workspacelen, "%jd", (cdr->billsec || !ast_tvzero(cdr->end) || ast_tvzero(cdr->answer)) ? cdr->billsec : (intmax_t)ast_tvdiff_ms(ast_tvnow(), cdr->answer) / 1000);
 	} else if (!strcasecmp(name, "disposition")) {
 		if (raw) {
 			snprintf(workspace, workspacelen, "%ld", cdr->disposition);
