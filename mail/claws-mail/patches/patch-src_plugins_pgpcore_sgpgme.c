$NetBSD: patch-src_plugins_pgpcore_sgpgme.c,v 1.1 2019/11/26 19:13:25 nia Exp $

--- src/plugins/pgpcore/sgpgme.c.orig	2019-04-25 07:33:35.000000000 +0000
+++ src/plugins/pgpcore/sgpgme.c
@@ -339,6 +339,7 @@ gchar *sgpgme_sigstat_info_full(gpgme_ct
 		gpgme_key_t key;
 		gpgme_error_t err;
 		const gchar *keytype, *keyid, *uid;
+		time_t ts;
 		
 		err = gpgme_get_key(ctx, sig->fpr, &key, 0);
 
