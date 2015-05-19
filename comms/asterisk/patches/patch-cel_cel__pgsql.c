$NetBSD: patch-cel_cel__pgsql.c,v 1.1 2015/05/19 07:52:14 jnemeth Exp $

--- cel/cel_pgsql.c.orig	2014-05-09 22:28:40.000000000 +0000
+++ cel/cel_pgsql.c
@@ -167,7 +167,7 @@ static void pgsql_log(const struct ast_e
 			if (strcmp(cur->name, "eventtime") == 0) {
 				if (strncmp(cur->type, "int", 3) == 0) {
 					LENGTHEN_BUF2(13);
-					ast_str_append(&sql2, 0, "%s%ld", SEP, (long) record.event_time.tv_sec);
+					ast_str_append(&sql2, 0, "%s%jd", SEP, (intmax_t) record.event_time.tv_sec);
 				} else if (strncmp(cur->type, "float", 5) == 0) {
 					LENGTHEN_BUF2(31);
 					ast_str_append(&sql2, 0, "%s%f",
