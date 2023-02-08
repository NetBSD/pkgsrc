$NetBSD: patch-lib_gssapi_krb5_arcfour.c,v 1.1 2023/02/08 07:41:25 wiz Exp $

Fix for CVE-2022-45142 from Helmut Grohne <helmut@subdivi.de>

--- lib/gssapi/krb5/arcfour.c.orig	2022-11-15 18:56:58.000000000 +0000
+++ lib/gssapi/krb5/arcfour.c
@@ -365,7 +365,7 @@ _gssapi_verify_mic_arcfour(OM_uint32 * m
 	return GSS_S_FAILURE;
     }
 
-    cmp = (ct_memcmp(cksum_data, p + 8, 8) == 0);
+    cmp = (ct_memcmp(cksum_data, p + 8, 8) != 0);
     if (cmp) {
 	*minor_status = 0;
 	return GSS_S_BAD_MIC;
@@ -730,7 +730,7 @@ OM_uint32 _gssapi_unwrap_arcfour(OM_uint
 	return GSS_S_FAILURE;
     }
 
-    cmp = (ct_memcmp(cksum_data, p0 + 16, 8) == 0); /* SGN_CKSUM */
+    cmp = (ct_memcmp(cksum_data, p0 + 16, 8) != 0); /* SGN_CKSUM */
     if (cmp) {
 	_gsskrb5_release_buffer(minor_status, output_message_buffer);
 	*minor_status = 0;
