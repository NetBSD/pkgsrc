$NetBSD: patch-main_cel.c,v 1.1.1.1 2016/10/25 08:17:05 jnemeth Exp $

--- main/cel.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ main/cel.c
@@ -790,7 +790,7 @@ struct ast_channel *ast_cel_fabricate_ch
 	}
 
 	if (ast_strlen_zero(cfg->general->date_format)) {
-		snprintf(timebuf, sizeof(timebuf), "%ld.%06ld", (long) record.event_time.tv_sec,
+		snprintf(timebuf, sizeof(timebuf), "%jd.%06ld", (intmax_t) record.event_time.tv_sec,
 				(long) record.event_time.tv_usec);
 	} else {
 		struct ast_tm tm;
