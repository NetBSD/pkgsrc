$NetBSD: patch-funcs_func__strings.c,v 1.1 2014/07/02 03:06:24 jnemeth Exp $

--- funcs/func_strings.c.orig	2014-05-21 19:05:32.000000000 +0000
+++ funcs/func_strings.c
@@ -790,6 +790,8 @@ static struct ast_custom_function filter
 	.read = filter,
 };
 
+RAII_DECL(struct ast_str *, str, ast_free);
+
 static int replace(struct ast_channel *chan, const char *cmd, char *data, struct ast_str **buf, ssize_t len)
 {
 	AST_DECLARE_APP_ARGS(args,
@@ -798,7 +800,7 @@ static int replace(struct ast_channel *c
 		AST_APP_ARG(replace);
 	);
 	char *strptr, *varsubst;
-	RAII_VAR(struct ast_str *, str, ast_str_create(16), ast_free);
+	RAII_VAR(struct ast_str *, str, ast_str_create(16));
 	char find[256]; /* Only 256 characters possible */
 	char replace[2] = "";
 	size_t unused;
