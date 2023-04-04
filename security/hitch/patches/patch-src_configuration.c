$NetBSD: patch-src_configuration.c,v 1.4 2023/04/04 21:51:07 tpaul Exp $

Use SUBST var for OSCP_DIR, Avoid d_type on Illumos.

--- src/configuration.c.orig	2021-11-29 12:09:28.000000000 +0000
+++ src/configuration.c
@@ -215,7 +215,7 @@ config_new(void)
 	r->CERT_FILES			= NULL;
 	r->LISTEN_ARGS			= NULL;
 	r->PEM_DIR			= NULL;
-	r->OCSP_DIR			= strdup("/var/lib/hitch/");
+	r->OCSP_DIR			= strdup("@HITCH_OCSP@/");
 	AN(r->OCSP_DIR);
 	r->OCSP_VFY			= 0;
 	r->OCSP_RESP_TMO		= 10.0;
@@ -1198,9 +1198,10 @@ config_scan_pem_dir(char *pemdir, hitch_
 			if (fnmatch(cfg->PEM_DIR_GLOB, d[i]->d_name, 0))
 				continue;
 		}
+#ifndef __sun
 		if (d[i]->d_type != DT_UNKNOWN && d[i]->d_type != DT_REG)
 			continue;
-
+#endif
 		fpath = malloc(plen);
 		AN(fpath);
 
@@ -1211,8 +1212,11 @@ config_scan_pem_dir(char *pemdir, hitch_
 			retval = 1;
 			break;
 		}
-
+#ifndef __sun
 		if (d[i]->d_type == DT_UNKNOWN) {
+#else
+		if (1) {
+#endif
 			/* The underlying filesystem does not support d_type. */
 			if (lstat(fpath, &st) < 0) {
 				fprintf(stderr, "Warning: unable to stat '%s': %s. Skipping.\n",
@@ -1455,7 +1459,7 @@ create_alpn_callback_data(hitch_config *
 
 	// first remove spaces while copying to cfg->ALPN_PROTOS_LV
 	for(j = 0; j < l; j++)
-		if (!isspace(cfg->ALPN_PROTOS[j])) {
+		if (!isspace((unsigned char)cfg->ALPN_PROTOS[j])) {
 			cfg->ALPN_PROTOS_LV[i] = cfg->ALPN_PROTOS[j];
 			i++;
 		}
