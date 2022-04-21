$NetBSD: patch-lib_dns_gssapi__link.c,v 1.2 2022/04/21 14:14:46 taca Exp $

* Take from NetBSD base.

--- lib/dns/gssapi_link.c.orig	2022-04-11 15:28:12.000000000 +0000
+++ lib/dns/gssapi_link.c
@@ -128,6 +128,9 @@ gssapi_sign(dst_context_t *dctx, isc_buf
 	gss_ctx_id_t gssctx = dctx->key->keydata.gssctx;
 	char buf[1024];
 
+	if (sizeof(buf) < sig->length)
+		abort();
+
 	/*
 	 * Convert the data we wish to sign into a structure gssapi can
 	 * understand.
