$NetBSD: patch-lib_engine_components_ldap_ldap-book.h,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/ldap/ldap-book.h.orig	2013-10-15 12:53:34.000000000 +0000
+++ lib/engine/components/ldap/ldap-book.h
@@ -40,7 +40,13 @@
 #define __LDAP_BOOK_H__
 
 #include <vector>
+#if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 #include <libxml/tree.h>
 #include <glib/gi18n.h>
 
@@ -88,11 +94,11 @@ namespace OPENLDAP
   public:
 
     Book (Ekiga::ServiceCore &_core,
-	  std::tr1::shared_ptr<xmlDoc> _doc,
+	  shared_ptr<xmlDoc> _doc,
 	  xmlNodePtr node);
 
     Book (Ekiga::ServiceCore &_core,
-	  std::tr1::shared_ptr<xmlDoc> _doc,
+	  shared_ptr<xmlDoc> _doc,
     	  OPENLDAP::BookInfo _bookinfo);
 
     ~Book ();
@@ -135,7 +141,7 @@ namespace OPENLDAP
 				 Ekiga::Form &form);
 
     Ekiga::ServiceCore &core;
-    std::tr1::shared_ptr<xmlDoc> doc;
+    shared_ptr<xmlDoc> doc;
     xmlNodePtr node;
 
     xmlNodePtr name_node;
