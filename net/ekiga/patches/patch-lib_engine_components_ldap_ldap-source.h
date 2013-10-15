$NetBSD: patch-lib_engine_components_ldap_ldap-source.h,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/ldap/ldap-source.h.orig	2013-10-15 13:02:38.000000000 +0000
+++ lib/engine/components/ldap/ldap-source.h
@@ -76,7 +76,7 @@ namespace OPENLDAP
   private:
 
     Ekiga::ServiceCore &core;
-    std::tr1::shared_ptr<xmlDoc> doc;
+    shared_ptr<xmlDoc> doc;
 
     struct BookInfo bookinfo;
 
