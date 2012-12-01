$NetBSD: patch-include_ptclib_pldap.h,v 1.3 2012/12/01 15:28:03 darcy Exp $

- Allow building on Solaris

--- include/ptclib/pldap.h.orig 2012-08-23 02:13:03.000000000 +0000
+++ include/ptclib/pldap.h
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

     /**Start encrypted connection
