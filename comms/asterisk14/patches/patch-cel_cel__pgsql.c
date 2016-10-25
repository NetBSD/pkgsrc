$NetBSD: patch-cel_cel__pgsql.c,v 1.1.1.1 2016/10/25 08:17:08 jnemeth Exp $

--- cel/cel_pgsql.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ cel/cel_pgsql.c
@@ -205,7 +205,7 @@ static void pgsql_log(struct ast_event *
 			if (strcmp(cur->name, "eventtime") == 0) {
 				if (strncmp(cur->type, "int", 3) == 0) {
 					LENGTHEN_BUF2(13);
-					ast_str_append(&sql2, 0, "%s%ld", SEP, (long) record.event_time.tv_sec);
+					ast_str_append(&sql2, 0, "%s%jd", SEP, (intmax_t) record.event_time.tv_sec);
 				} else if (strncmp(cur->type, "float", 5) == 0) {
 					LENGTHEN_BUF2(31);
 					ast_str_append(&sql2, 0, "%s%f",
