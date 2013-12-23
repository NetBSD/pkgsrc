$NetBSD: patch-main_http.c,v 1.1 2013/12/23 01:34:03 jnemeth Exp $

--- main/http.c.orig	2013-08-21 17:07:06.000000000 +0000
+++ main/http.c
@@ -1014,6 +1014,8 @@ static void add_redirect(const char *val
 	AST_RWLIST_UNLOCK(&uri_redirects);
 }
 
+RAII_DECL(struct ast_sockaddr *, addrs, ast_free);
+
 static int __ast_http_load(int reload)
 {
 	struct ast_config *cfg;
@@ -1024,7 +1026,7 @@ static int __ast_http_load(int reload)
 	struct http_uri_redirect *redirect;
 	struct ast_flags config_flags = { reload ? CONFIG_FLAG_FILEUNCHANGED : 0 };
 	uint32_t bindport = DEFAULT_PORT;
-	RAII_VAR(struct ast_sockaddr *, addrs, NULL, ast_free);
+	RAII_VAR(struct ast_sockaddr *, addrs, NULL);
 	int num_addrs = 0;
 	int http_tls_was_enabled = 0;
 
