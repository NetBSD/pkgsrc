$NetBSD: patch-main_cdr.c,v 1.2 2015/10/27 08:49:01 jnemeth Exp $

--- main/cdr.c.orig	2015-10-09 22:23:39.000000000 +0000
+++ main/cdr.c
@@ -260,7 +260,7 @@ static const char *ast_cdr_getvar_intern
 static void cdr_get_tv(struct timeval when, const char *fmt, char *buf, int bufsize)
 {
 	if (fmt == NULL) {	/* raw mode */
-		snprintf(buf, bufsize, "%ld.%06ld", (long)when.tv_sec, (long)when.tv_usec);
+		snprintf(buf, bufsize, "%jd.%06ld", (intmax_t)when.tv_sec, (long)when.tv_usec);
 	} else {
 		if (when.tv_sec) {
 			struct ast_tm tm;
@@ -307,12 +307,12 @@ void ast_cdr_getvar(struct ast_cdr *cdr,
 	else if (!strcasecmp(name, "end"))
 		cdr_get_tv(cdr->end, raw ? NULL : fmt, workspace, workspacelen);
 	else if (!strcasecmp(name, "duration")) {
-		snprintf(workspace, workspacelen, "%ld", cdr->end.tv_sec != 0 ? cdr->duration : (long)ast_tvdiff_ms(ast_tvnow(), cdr->start) / 1000);
+		snprintf(workspace, workspacelen, "%jd", cdr->end.tv_sec != 0 ? cdr->duration : (intmax_t)ast_tvdiff_ms(ast_tvnow(), cdr->start) / 1000);
 	} else if (!strcasecmp(name, "billsec")) {
-		snprintf(workspace, workspacelen, "%ld", (cdr->billsec || !ast_tvzero(cdr->end) || ast_tvzero(cdr->answer)) ? cdr->billsec : (long)ast_tvdiff_ms(ast_tvnow(), cdr->answer) / 1000);	
+		snprintf(workspace, workspacelen, "%jd", (cdr->billsec || !ast_tvzero(cdr->end) || ast_tvzero(cdr->answer)) ? cdr->billsec : (intmax_t)ast_tvdiff_ms(ast_tvnow(), cdr->answer) / 1000);	
 	} else if (!strcasecmp(name, "disposition")) {
 		if (raw) {
-			snprintf(workspace, workspacelen, "%ld", cdr->disposition);
+			snprintf(workspace, workspacelen, "%jd", (intmax_t)cdr->disposition);
 		} else {
 			ast_copy_string(workspace, ast_cdr_disp2str(cdr->disposition), workspacelen);
 		}
