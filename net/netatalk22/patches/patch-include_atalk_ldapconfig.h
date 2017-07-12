$NetBSD: patch-include_atalk_ldapconfig.h,v 1.2 2017/07/12 13:56:00 hauke Exp $

Correct an erroneous patch that was unfortunately submitted upstream.

Providing an empty header because we do not support ACLs only serves
to break ldap support.
							     
--- include/atalk/ldapconfig.h.orig	2017-07-09 11:03:31.000000000 +0000
+++ include/atalk/ldapconfig.h
@@ -1,5 +1,4 @@
 #ifdef HAVE_LDAP
-#ifdef HAVE_ACLS
 
 #ifndef LDAPCONFIG_H
 #define LDAPCONFIG_H
@@ -40,5 +39,5 @@ extern struct pref_array prefs_array[];
 extern int ldap_config_valid;
 
 #endif /* LDAPCONFIG_H */
-#endif /* HAVE_ACLS */
+
 #endif /* HAVE_LDAP */
