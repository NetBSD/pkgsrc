$NetBSD: patch-main_http.c,v 1.2 2015/05/19 07:52:14 jnemeth Exp $

--- main/http.c.orig	2015-02-21 14:04:54.000000000 +0000
+++ main/http.c
@@ -272,7 +272,7 @@ static int static_callback(struct ast_tc
 	}
 
 	/* make "Etag:" http header value */
-	snprintf(etag, sizeof(etag), "\"%ld\"", (long)st.st_mtime);
+	snprintf(etag, sizeof(etag), "\"%jd\"", (intmax_t)st.st_mtime);
 
 	/* make "Last-Modified:" http header value */
 	tv.tv_sec = st.st_mtime;
@@ -1062,6 +1062,8 @@ static void add_redirect(const char *val
 	AST_RWLIST_UNLOCK(&uri_redirects);
 }
 
+RAII_DECL(struct ast_sockaddr *, addrs, ast_free);
+
 static int __ast_http_load(int reload)
 {
 	struct ast_config *cfg;
@@ -1072,7 +1074,7 @@ static int __ast_http_load(int reload)
 	struct http_uri_redirect *redirect;
 	struct ast_flags config_flags = { reload ? CONFIG_FLAG_FILEUNCHANGED : 0 };
 	uint32_t bindport = DEFAULT_PORT;
-	RAII_VAR(struct ast_sockaddr *, addrs, NULL, ast_free);
+	RAII_VAR(struct ast_sockaddr *, addrs, NULL);
 	int num_addrs = 0;
 	int http_tls_was_enabled = 0;
 
