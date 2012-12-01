$NetBSD: patch-src_ptclib_pldap.cxx,v 1.2 2012/12/01 15:28:03 darcy Exp $

- Add Solaris support

--- src/ptclib/pldap.cxx.orig	2009-09-21 02:25:24.000000000 +0200
+++ src/ptclib/pldap.cxx	2012-04-18 20:29:09.841685925 +0200
@@ -132,13 +132,8 @@ PBoolean PLDAPSession::Bind(const PStrin
   else
     whoPtr = who;
 
-#ifdef SOLARIS
-  static const int AuthMethodCode[NumAuthenticationMethod2] = {
-    LDAP_AUTH_SIMPLE, LDAP_AUTH_SASL, LDAP_AUTH_KRBV41_30, LDAP_AUTH_KRBV42_30
-#else
   static const int AuthMethodCode[NumAuthenticationMethod] = {
     LDAP_AUTH_SIMPLE, LDAP_AUTH_SASL, LDAP_AUTH_KRBV4
-#endif
   };
   errorNumber = ldap_bind_s(ldapContext, whoPtr, passwd, AuthMethodCode[authMethod]);
   return errorNumber == LDAP_SUCCESS;
