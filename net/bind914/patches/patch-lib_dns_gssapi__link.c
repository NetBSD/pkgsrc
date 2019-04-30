$NetBSD: patch-lib_dns_gssapi__link.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* C syntax.

--- lib/dns/gssapi_link.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/dns/gssapi_link.c
@@ -190,9 +190,12 @@ gssapi_verify(dst_context_t *dctx, const
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
