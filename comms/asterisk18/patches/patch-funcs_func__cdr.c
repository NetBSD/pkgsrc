$NetBSD: patch-funcs_func__cdr.c,v 1.2 2021/06/13 07:57:53 jnemeth Exp $

--- funcs/func_cdr.c.orig	2018-05-07 17:23:06.705808560 +0000
+++ funcs/func_cdr.c
@@ -547,7 +547,7 @@ static int cdr_write(struct ast_channel 
 
 		ast_log(LOG_WARNING, "Using the %s function to set 'amaflags' is deprecated. Please use the CHANNEL function instead.\n",
 			cmd);
-		if (isdigit(*value)) {
+		if (isdigit((unsigned char)*value)) {
 			if (sscanf(value, "%30d", &amaflags) != 1) {
 				amaflags = AST_AMA_NONE;
 			}
