$NetBSD: patch-imap-common.c,v 1.1 2020/08/29 13:43:54 leot Exp $

Add support for OAUTHBEARER (OAuth 2.0 bearer tokens, as documented by
RFC 7628) for IMAP.

Patch shared upstream via:

 <https://github.com/nicm/fdm/pull/84>

--- imap-common.c.orig	2019-02-12 22:08:26.000000000 +0000
+++ imap-common.c
@@ -45,6 +45,7 @@ int	imap_state_connect(struct account *,
 int	imap_state_capability1(struct account *, struct fetch_ctx *);
 int	imap_state_capability2(struct account *, struct fetch_ctx *);
 int	imap_state_starttls(struct account *, struct fetch_ctx *);
+int	imap_state_oauthbearer_auth(struct account *, struct fetch_ctx *);
 int	imap_state_cram_md5_auth(struct account *, struct fetch_ctx *);
 int	imap_state_login(struct account *, struct fetch_ctx *);
 int	imap_state_user(struct account *, struct fetch_ctx *);
@@ -295,6 +296,12 @@ imap_pick_auth(struct account *a, struct
 {
 	struct fetch_imap_data	*data = a->data;
 
+	/* Try OAUTHBEARER, if requested by user and if server supports it. */
+	if (data->oauthbearer && (data->capa & IMAP_CAPA_AUTH_OAUTHBEARER)) {
+		fctx->state = imap_state_oauthbearer_auth;
+		return (FETCH_AGAIN);
+	}
+
 	/* Try CRAM-MD5, if server supports it and user allows it. */
 	if (!data->nocrammd5 && (data->capa & IMAP_CAPA_AUTH_CRAM_MD5)) {
 		if (imap_putln(a,
@@ -401,6 +408,9 @@ imap_state_capability1(struct account *a
 	if (strstr(line, "AUTH=CRAM-MD5") != NULL)
 		data->capa |= IMAP_CAPA_AUTH_CRAM_MD5;
 
+	if (strstr(line, "AUTH=OAUTHBEARER") != NULL)
+		data->capa |= IMAP_CAPA_AUTH_OAUTHBEARER;
+
 	/* Use XYZZY to detect Google brokenness. */
 	if (strstr(line, "XYZZY") != NULL)
 		data->capa |= IMAP_CAPA_XYZZY;
@@ -470,6 +480,31 @@ imap_state_starttls(struct account *a, s
 	return (imap_pick_auth(a, fctx));
 }
 
+/* OAUTHBEARER auth state. */
+int
+imap_state_oauthbearer_auth(struct account *a, struct fetch_ctx *fctx)
+{
+	struct fetch_imap_data	*data = a->data;
+	char			*src, *b64;
+
+	xasprintf(&src,
+	    "n,a=%s,\001host=%s\001port=%d\001auth=Bearer %s\001\001",
+	    data->user, data->server.host, data->server.port, data->pass);
+	b64 = imap_base64_encode(src);
+	xfree(src);
+
+	if (imap_putln(a,
+	    "%u AUTHENTICATE OAUTHBEARER %s", ++data->tag, b64) != 0) {
+		xfree(b64);
+		return (FETCH_ERROR);
+	}
+	xfree(b64);
+
+	fctx->state = imap_state_pass;
+	return (FETCH_BLOCK);
+}
+
+
 /* CRAM-MD5 auth state. */
 int
 imap_state_cram_md5_auth(struct account *a, struct fetch_ctx *fctx)
