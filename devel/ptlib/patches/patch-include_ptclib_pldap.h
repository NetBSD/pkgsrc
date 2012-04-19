$NetBSD: patch-include_ptclib_pldap.h,v 1.1 2012/04/19 12:34:43 hans Exp $

--- include/ptclib/pldap.h.orig	2009-09-21 02:25:53.000000000 +0200
+++ include/ptclib/pldap.h	2012-04-18 20:29:59.394305646 +0200
@@ -103,12 +103,7 @@ class PLDAPSession : public PObject
       AuthSimple,
       AuthSASL,
       AuthKerberos,
-#ifdef SOLARIS
-      NumAuthenticationMethod1,
-      NumAuthenticationMethod2
-#else
       NumAuthenticationMethod
-#endif
     };
 
     /**Bind to the remote LDAP server.
