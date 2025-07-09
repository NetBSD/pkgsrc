$NetBSD: patch-contrib_slapd-modules_smbk5pwd_smbk5pwd.c,v 1.2 2025/07/09 09:18:01 jperkin Exp $

Detect hdb_generate_key_set_password() signature change in Heimdal 7.1

Details can be found here:
https://github.com/heimdal/heimdal/issues/246

--- contrib/slapd-modules/smbk5pwd/smbk5pwd.c.orig	2025-05-22 17:56:21.000000000 +0000
+++ contrib/slapd-modules/smbk5pwd/smbk5pwd.c
@@ -398,8 +398,13 @@ static int smbk5pwd_exop_passwd(
 				op->o_log_prefix, e->e_name.bv_val );
 		}
 
+#if (HDB_INTERFACE_VERSION >= 10)
 		ret = hdb_generate_key_set_password(context, ent.principal,
 			qpw->rs_new.bv_val, &ent.keys.val, &nkeys);
+#else
+		ret = hdb_generate_key_set_password(context, ent.principal,
+			qpw->rs_new.bv_val, NULL, 0, &ent.keys.val, &nkeys);
+#endif
 		ent.keys.len = nkeys;
 		hdb_seal_keys(context, db, &ent);
 		krb5_free_principal( context, ent.principal );
