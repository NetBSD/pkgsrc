$NetBSD: patch-lib_dns_spnego.c,v 1.1 2019/04/30 03:34:34 taca Exp $

* Avoid gcc warning.

--- lib/dns/spnego.c.orig	2019-04-06 20:09:59.000000000 +0000
+++ lib/dns/spnego.c
@@ -1517,7 +1517,7 @@ spnego_initial(OM_uint32 *minor_status,
 	gss_buffer_desc	krb5_output_token = GSS_C_EMPTY_BUFFER;
 	unsigned char *buf = NULL;
 	size_t buf_size;
-	size_t len;
+	size_t len = 0;	/* XXX: gcc */
 	int ret;
 
 	(void)mech_type;
