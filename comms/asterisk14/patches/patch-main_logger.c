$NetBSD: patch-main_logger.c,v 1.1.1.1 2016/10/25 08:17:07 jnemeth Exp $

--- main/logger.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ main/logger.c
@@ -674,7 +674,7 @@ void ast_queue_log(const char *queuename
 
 	if (qlog) {
 		va_start(ap, fmt);
-		qlog_len = snprintf(qlog_msg, sizeof(qlog_msg), "%ld|%s|%s|%s|%s|", (long)time(NULL), callid, queuename, agent, event);
+		qlog_len = snprintf(qlog_msg, sizeof(qlog_msg), "%jd|%s|%s|%s|%s|", (intmax_t)time(NULL), callid, queuename, agent, event);
 		vsnprintf(qlog_msg + qlog_len, sizeof(qlog_msg) - qlog_len, fmt, ap);
 		va_end(ap);
 		AST_RWLIST_RDLOCK(&logchannels);
@@ -714,7 +714,7 @@ static int rotate_file(const char *filen
 		}
 		break;
 	case TIMESTAMP:
-		snprintf(new, sizeof(new), "%s.%ld", filename, (long)time(NULL));
+		snprintf(new, sizeof(new), "%s.%jd", filename, (intmax_t)time(NULL));
 		if (rename(filename, new)) {
 			fprintf(stderr, "Unable to rename file '%s' to '%s'\n", filename, new);
 			res = -1;
