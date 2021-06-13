$NetBSD: patch-main_ast__expr2.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- main/ast_expr2.c.orig	2018-05-07 17:49:06.171631311 +0000
+++ main/ast_expr2.c
@@ -2545,9 +2545,9 @@ make_str (const char *s)
 		return(NULL);
 	}
 
-	for (i = 0, isint = (isdigit(s[0]) || s[0] == '-' || s[0]=='.'); isint && i < strlen(s); i++)
+	for (i = 0, isint = (isdigit((unsigned char)s[0]) || s[0] == '-' || s[0]=='.'); isint && i < strlen(s); i++)
 	{
-		if (!isdigit(s[i]) && s[i] != '.') {
+		if (!isdigit((unsigned char)s[i]) && s[i] != '.') {
 			isint = 0;
 			break;
 		}
