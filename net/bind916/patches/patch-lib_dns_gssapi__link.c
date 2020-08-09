$NetBSD: patch-lib_dns_gssapi__link.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base.

--- lib/dns/gssapi_link.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/dns/gssapi_link.c
@@ -179,9 +179,12 @@ gssapi_verify(dst_context_t *dctx, const
 	gss_buffer_desc gmessage, gsig;
 	OM_uint32 minor, gret;
 	gss_ctx_id_t gssctx = dctx->key->keydata.gssctx;
-	unsigned char buf[sig->length];
+	unsigned char buf[4096];
 	char err[1024];
 
+	if (sizeof(buf) < sig->length)
+		abort();
+
 	/*
 	 * Convert the data we wish to sign into a structure gssapi can
 	 * understand.
