$NetBSD: patch-src_configuration.c,v 1.3 2020/05/17 15:01:41 nia Exp $

Sane default options.

--- src/configuration.c.orig	2019-11-26 13:33:39.000000000 +0000
+++ src/configuration.c
@@ -209,7 +209,7 @@ config_new(void)
 	r->CERT_FILES			= NULL;
 	r->LISTEN_ARGS			= NULL;
 	r->PEM_DIR			= NULL;
-	r->OCSP_DIR			= strdup("/var/lib/hitch/");
+	r->OCSP_DIR			= strdup("@HITCH_OCSP@/");
 	AN(r->OCSP_DIR);
 	r->OCSP_VFY			= 0;
 	r->OCSP_RESP_TMO		= 10.0;
@@ -1340,7 +1340,7 @@ create_alpn_callback_data(hitch_config *
 
 	// first remove spaces while copying to cfg->ALPN_PROTOS_LV
 	for(j = 0; j < l; j++)
-		if (!isspace(cfg->ALPN_PROTOS[j])) {
+		if (!isspace((unsigned char)cfg->ALPN_PROTOS[j])) {
 			cfg->ALPN_PROTOS_LV[i] = cfg->ALPN_PROTOS[j];
 			i++;
 		}
