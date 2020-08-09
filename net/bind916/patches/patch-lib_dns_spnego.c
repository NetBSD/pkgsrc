$NetBSD: patch-lib_dns_spnego.c,v 1.1 2020/08/09 15:20:22 taca Exp $

* Take from NetBSD base, avoid gcc warning.

--- lib/dns/spnego.c.orig	2020-05-06 09:59:35.000000000 +0000
+++ lib/dns/spnego.c
@@ -1503,7 +1503,7 @@ spnego_initial(OM_uint32 *minor_status,
 	gss_buffer_desc krb5_output_token = GSS_C_EMPTY_BUFFER;
 	unsigned char *buf = NULL;
 	size_t buf_size;
-	size_t len;
+	size_t len = 0;	/* XXX: gcc */
 	int ret;
 
 	(void)mech_type;
