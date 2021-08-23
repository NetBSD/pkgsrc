$NetBSD: patch-libraries_libldap_init.c,v 1.1 2021/08/23 09:58:58 adam Exp $

--- libraries/libldap/init.c.orig	2021-07-27 17:44:47.000000000 +0000
+++ libraries/libldap/init.c
@@ -691,7 +691,11 @@ void ldap_int_initialize( struct ldapopt
 #if defined(HAVE_TLS) || defined(HAVE_CYRUS_SASL)
 	LDAP_MUTEX_LOCK( &ldap_int_hostname_mutex );
 	{
-		char	*name = ldap_int_hostname;
+		char	*name;
+#if defined(LDAP_R_COMPILE)
+		ldap_pvt_thread_initialize();
+#endif
+		name = ldap_int_hostname;
 
 		ldap_int_hostname = ldap_pvt_get_fqdn( name );
 
