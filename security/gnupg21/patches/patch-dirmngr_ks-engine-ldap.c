$NetBSD: patch-dirmngr_ks-engine-ldap.c,v 1.1 2015/09/30 12:56:47 fhajny Exp $

This must have been an ugly typo. Fix build on SunOS.

--- dirmngr/ks-engine-ldap.c.orig	2015-06-17 06:39:24.000000000 +0000
+++ dirmngr/ks-engine-ldap.c
@@ -513,7 +513,7 @@ my_ldap_connect (parsed_uri_t uri, LDAP
 #endif /* LDAP_OPT_X_TLS_CACERTFILE && HAVE_LDAP_SET_OPTION */
 #endif
 
-#ifndef HAVE_LDAP_START_TLS_S
+#ifdef HAVE_LDAP_START_TLS_S
   if (uri->use_tls)
     {
       /* XXX: We need an option to determine whether to abort if the
