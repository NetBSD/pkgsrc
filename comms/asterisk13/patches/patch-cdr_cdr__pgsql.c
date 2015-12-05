$NetBSD: patch-cdr_cdr__pgsql.c,v 1.1.1.1 2015/12/05 23:29:09 jnemeth Exp $

--- cdr/cdr_pgsql.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ cdr/cdr_pgsql.c
@@ -283,7 +283,7 @@ static int pgsql_log(struct ast_cdr *cdr
 			if (strcmp(cur->name, "start") == 0 || strcmp(cur->name, "calldate") == 0) {
 				if (strncmp(cur->type, "int", 3) == 0) {
 					LENGTHEN_BUF2(13);
-					ast_str_append(&sql2, 0, "%s%ld", first ? "" : ",", (long) cdr->start.tv_sec);
+					ast_str_append(&sql2, 0, "%s%jd", first ? "" : ",", (intmax_t) cdr->start.tv_sec);
 				} else if (strncmp(cur->type, "float", 5) == 0) {
 					LENGTHEN_BUF2(31);
 					ast_str_append(&sql2, 0, "%s%f", first ? "" : ",", (double)cdr->start.tv_sec + (double)cdr->start.tv_usec / 1000000.0);
@@ -297,7 +297,7 @@ static int pgsql_log(struct ast_cdr *cdr
 			} else if (strcmp(cur->name, "answer") == 0) {
 				if (strncmp(cur->type, "int", 3) == 0) {
 					LENGTHEN_BUF2(13);
-					ast_str_append(&sql2, 0, "%s%ld", first ? "" : ",", (long) cdr->answer.tv_sec);
+					ast_str_append(&sql2, 0, "%s%jd", first ? "" : ",", (intmax_t) cdr->answer.tv_sec);
 				} else if (strncmp(cur->type, "float", 5) == 0) {
 					LENGTHEN_BUF2(31);
 					ast_str_append(&sql2, 0, "%s%f", first ? "" : ",", (double)cdr->answer.tv_sec + (double)cdr->answer.tv_usec / 1000000.0);
@@ -311,7 +311,7 @@ static int pgsql_log(struct ast_cdr *cdr
 			} else if (strcmp(cur->name, "end") == 0) {
 				if (strncmp(cur->type, "int", 3) == 0) {
 					LENGTHEN_BUF2(13);
-					ast_str_append(&sql2, 0, "%s%ld", first ? "" : ",", (long) cdr->end.tv_sec);
+					ast_str_append(&sql2, 0, "%s%jd", first ? "" : ",", (intmax_t) cdr->end.tv_sec);
 				} else if (strncmp(cur->type, "float", 5) == 0) {
 					LENGTHEN_BUF2(31);
 					ast_str_append(&sql2, 0, "%s%f", first ? "" : ",", (double)cdr->end.tv_sec + (double)cdr->end.tv_usec / 1000000.0);
