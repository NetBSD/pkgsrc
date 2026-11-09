$NetBSD: patch-main_cel.c,v 1.1 2026/11/09 05:37:21 jnemeth Exp $

--- main/cel.c.orig	2026-04-09 16:37:03.000000000 +0000
+++ main/cel.c
@@ -680,7 +680,7 @@ static int cel_format_eventtime(struct cel_config *cfg
 	}
 
 	if (ast_strlen_zero(cfg->general->date_format)) {
-		snprintf(timebuf, len, "%ld.%06ld", (long) eventtime.tv_sec,
+		snprintf(timebuf, len, "%jd.%06ld", (intmax_t) eventtime.tv_sec,
 				(long) eventtime.tv_usec);
 	} else {
 		struct ast_tm tm;
