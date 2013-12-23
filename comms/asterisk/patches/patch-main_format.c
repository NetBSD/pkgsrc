$NetBSD: patch-main_format.c,v 1.1 2013/12/23 01:34:03 jnemeth Exp $

--- main/format.c.orig	2013-06-12 02:25:23.000000000 +0000
+++ main/format.c
@@ -914,9 +914,11 @@ int init_framer(void)
 	return 0;
 }
 
+RAII_DECL(struct ast_format_list *, entry, ao2_cleanup);
+
 static int format_list_add_custom(struct ast_format_list *new)
 {
-	RAII_VAR(struct ast_format_list *, entry, NULL, ao2_cleanup);
+	RAII_VAR(struct ast_format_list *, entry, NULL);
 	if (!(entry = ao2_alloc(sizeof(*entry), NULL))) {
 		return -1;
 	}
