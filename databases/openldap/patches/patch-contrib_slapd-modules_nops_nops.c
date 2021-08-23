$NetBSD: patch-contrib_slapd-modules_nops_nops.c,v 1.1 2021/08/23 09:58:58 adam Exp $

--- contrib/slapd-modules/nops/nops.c.orig	2021-07-27 17:44:47.000000000 +0000
+++ contrib/slapd-modules/nops/nops.c
@@ -69,10 +69,15 @@ nops_modify( Operation *op, SlapReply *r
 	int rc;
 	
 	if ((m = op->orm_modlist) == NULL) {
+		slap_callback *cb = op->o_callback;
+
 		op->o_bd->bd_info = (BackendInfo *)(on->on_info);
+		op->o_callback = NULL;
 		send_ldap_error(op, rs, LDAP_INVALID_SYNTAX,
 				"nops() got null orm_modlist");
-		return(rs->sr_err);
+		op->o_callback = cb;
+
+		return (rs->sr_err);
 	}
 
 	op->o_bd = on->on_info->oi_origdb;
