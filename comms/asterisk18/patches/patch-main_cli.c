$NetBSD: patch-main_cli.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- main/cli.c.orig	2018-05-07 17:26:06.732494913 +0000
+++ main/cli.c
@@ -2440,7 +2440,7 @@ static char *parse_args(const char *s, i
 	cur = duplicate;
 
 	/* Remove leading spaces from the command */
-	while (isspace(*s)) {
+	while (isspace((unsigned char)*s)) {
 		cur++;
 		s++;
 	}
@@ -2627,7 +2627,7 @@ struct ast_vector_string *ast_cli_comple
 			continue;
 		}
 
-		while (i < max_equal && toupper(prevstr[i]) == toupper(retstr[i])) {
+		while (i < max_equal && toupper((unsigned char)prevstr[i]) == toupper((unsigned char)retstr[i])) {
 			i++;
 		}
 
