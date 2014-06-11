$NetBSD: patch-include_atalk_ldapconfig.h,v 1.1 2014/06/11 11:03:56 hauke Exp $

--- include/atalk/ldapconfig.h.orig	2012-09-10 09:34:52.000000000 +0000
+++ include/atalk/ldapconfig.h
@@ -1,4 +1,5 @@
 #ifdef HAVE_LDAP
+#ifdef HAVE_ACLS
 
 #ifndef LDAPCONFIG_H
 #define LDAPCONFIG_H
@@ -39,5 +40,5 @@ extern struct pref_array prefs_array[];
 extern int ldap_config_valid;
 
 #endif /* LDAPCONFIG_H */
-
+#endif /* HAVE_ACLS */
 #endif /* HAVE_LDAP */
