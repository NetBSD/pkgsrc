$NetBSD: patch-ldap-ethers.c,v 1.1 2014/06/01 19:38:10 asau Exp $

--- ldap-ethers.c.orig	2009-11-06 10:28:08.000000000 +0000
+++ ldap-ethers.c
@@ -96,6 +96,10 @@ static char *ether_ntoa (const struct et
 static ent_context_t *ether_context = NULL;
 #endif
 
+#ifdef __FreeBSD__
+#define ether_addr_octet octet
+#endif
+
 static NSS_STATUS
 _nss_ldap_parse_ether (LDAPMessage * e,
 		       ldap_state_t * pvt,
