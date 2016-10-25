$NetBSD: patch-main_http.c,v 1.1.1.1 2016/10/25 08:17:05 jnemeth Exp $

--- main/http.c.orig	2015-10-09 21:48:48.000000000 +0000
+++ main/http.c
@@ -304,7 +304,7 @@ static int static_callback(struct ast_tc
 	}
 
 	/* make "Etag:" http header value */
-	snprintf(etag, sizeof(etag), "\"%ld\"", (long)st.st_mtime);
+	snprintf(etag, sizeof(etag), "\"%jd\"", (intmax_t)st.st_mtime);
 
 	/* make "Last-Modified:" http header value */
 	tv.tv_sec = st.st_mtime;
