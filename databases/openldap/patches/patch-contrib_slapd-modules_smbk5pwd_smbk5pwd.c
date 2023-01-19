$NetBSD: patch-contrib_slapd-modules_smbk5pwd_smbk5pwd.c,v 1.1 2023/01/19 15:08:26 manu Exp $

Detect hdb_generate_key_set_password() signature change in Heimdal 7.1

Details can be found here:
https://github.com/heimdal/heimdal/issues/246

--- contrib/slapd-modules/smbk5pwd/smbk5pwd.c.orig	2023-01-19 09:14:54.607644432 +0100
+++ contrib/slapd-modules/smbk5pwd/smbk5pwd.c	2023-01-19 09:18:41.602844881 +0100
@@ -396,10 +396,15 @@
 				"dn=\"%s\" missing krb5KeyVersionNumber\n",
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
 
