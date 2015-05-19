$NetBSD: patch-main_cel.c,v 1.1 2015/05/19 07:52:14 jnemeth Exp $

--- main/cel.c.orig	2014-05-09 22:28:40.000000000 +0000
+++ main/cel.c
@@ -515,7 +515,7 @@ struct ast_channel *ast_cel_fabricate_ch
 	}
 
 	if (ast_strlen_zero(cel_dateformat)) {
-		snprintf(timebuf, sizeof(timebuf), "%ld.%06ld", (long) record.event_time.tv_sec,
+		snprintf(timebuf, sizeof(timebuf), "%jd.%06ld", (intmax_t) record.event_time.tv_sec,
 				(long) record.event_time.tv_usec);
 	} else {
 		struct ast_tm tm;
