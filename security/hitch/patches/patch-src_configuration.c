$NetBSD: patch-src_configuration.c,v 1.1.4.1 2017/07/10 19:39:19 bsiegert Exp $

Sane default options.

--- src/configuration.c.orig	2016-12-15 10:34:22.000000000 +0000
+++ src/configuration.c
@@ -193,7 +193,7 @@ config_new(void)
 	fa->pspec = strdup("default");
 	HASH_ADD_KEYPTR(hh, r->LISTEN_ARGS, fa->pspec, strlen(fa->pspec), fa);
 	r->LISTEN_DEFAULT = fa;
-	r->OCSP_DIR           = strdup("/var/lib/hitch/");
+	r->OCSP_DIR           = strdup("@HITCH_OCSP@/");
 	r->OCSP_VFY = 0;
 	r->OCSP_RESP_TMO = 10.0;
 	r->OCSP_CONN_TMO = 4.0;
@@ -1116,7 +1116,7 @@ create_alpn_callback_data(hitch_config *
 
 	// first remove spaces while copying to cfg->ALPN_PROTOS_LV
 	for(j = 0; j < l; j++)
-		if (!isspace(cfg->ALPN_PROTOS[j])) {
+		if (!isspace((unsigned char)cfg->ALPN_PROTOS[j])) {
 			cfg->ALPN_PROTOS_LV[i] = cfg->ALPN_PROTOS[j];
 			i++;
 		}
