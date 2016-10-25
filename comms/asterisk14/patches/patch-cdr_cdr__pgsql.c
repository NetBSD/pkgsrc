$NetBSD: patch-cdr_cdr__pgsql.c,v 1.1.1.1 2016/10/25 08:17:07 jnemeth Exp $

--- cdr/cdr_pgsql.c.orig	2016-09-30 20:36:17.000000000 +0000
+++ cdr/cdr_pgsql.c
@@ -270,7 +270,7 @@ static int pgsql_log(struct ast_cdr *cdr
 			if (strcmp(cur->name, "start") == 0 || strcmp(cur->name, "calldate") == 0) {
 				if (strncmp(cur->type, "int", 3) == 0) {
 					LENGTHEN_BUF2(13);
-					ast_str_append(&sql2, 0, "%s%ld", separator, (long) cdr->start.tv_sec);
+					ast_str_append(&sql2, 0, "%s%jd", separator, (intmax_t) cdr->start.tv_sec);
 				} else if (strncmp(cur->type, "float", 5) == 0) {
 					LENGTHEN_BUF2(31);
 					ast_str_append(&sql2, 0, "%s%f", separator, (double)cdr->start.tv_sec + (double)cdr->start.tv_usec / 1000000.0);
@@ -284,7 +284,7 @@ static int pgsql_log(struct ast_cdr *cdr
 			} else if (strcmp(cur->name, "answer") == 0) {
 				if (strncmp(cur->type, "int", 3) == 0) {
 					LENGTHEN_BUF2(13);
-					ast_str_append(&sql2, 0, "%s%ld", separator, (long) cdr->answer.tv_sec);
+					ast_str_append(&sql2, 0, "%s%jd", separator, (intmax_t) cdr->answer.tv_sec);
 				} else if (strncmp(cur->type, "float", 5) == 0) {
 					LENGTHEN_BUF2(31);
 					ast_str_append(&sql2, 0, "%s%f", separator, (double)cdr->answer.tv_sec + (double)cdr->answer.tv_usec / 1000000.0);
@@ -298,7 +298,7 @@ static int pgsql_log(struct ast_cdr *cdr
 			} else if (strcmp(cur->name, "end") == 0) {
 				if (strncmp(cur->type, "int", 3) == 0) {
 					LENGTHEN_BUF2(13);
-					ast_str_append(&sql2, 0, "%s%ld", separator, (long) cdr->end.tv_sec);
+					ast_str_append(&sql2, 0, "%s%jd", separator, (intmax_t) cdr->end.tv_sec);
 				} else if (strncmp(cur->type, "float", 5) == 0) {
 					LENGTHEN_BUF2(31);
 					ast_str_append(&sql2, 0, "%s%f", separator, (double)cdr->end.tv_sec + (double)cdr->end.tv_usec / 1000000.0);
