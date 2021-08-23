$NetBSD: patch-libraries_libldap_ldap-int.h,v 1.1 2021/08/23 09:58:58 adam Exp $

--- libraries/libldap/ldap-int.h.orig	2021-07-27 17:44:47.000000000 +0000
+++ libraries/libldap/ldap-int.h
@@ -866,7 +866,7 @@ LDAP_F (int) ldap_int_sasl_close LDAP_P(
 
 LDAP_F (int) ldap_int_sasl_external LDAP_P((
 	LDAP *ld, LDAPConn *conn,
-	const char* authid, ber_len_t ssf ));
+	const char* authid, ber_uint_t ssf ));
 
 LDAP_F (int) ldap_int_sasl_get_option LDAP_P(( LDAP *ld,
 	int option, void *arg ));
