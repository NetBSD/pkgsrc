$NetBSD: patch-lib_engine_components_ldap_ldap-book.cpp,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/ldap/ldap-book.cpp.orig	2013-10-15 13:02:29.000000000 +0000
+++ lib/engine/components/ldap/ldap-book.cpp
@@ -166,7 +166,7 @@ struct RefreshData
 /* actual implementation */
 
 OPENLDAP::Book::Book (Ekiga::ServiceCore &_core,
-		      std::tr1::shared_ptr<xmlDoc> _doc,
+		      shared_ptr<xmlDoc> _doc,
 		      xmlNodePtr _node):
   saslform(NULL), core(_core), doc(_doc), node(_node),
   name_node(NULL), uri_node(NULL), authcID_node(NULL), password_node(NULL),
@@ -335,7 +335,7 @@ OPENLDAP::Book::Book (Ekiga::ServiceCore
 }
 
 OPENLDAP::Book::Book (Ekiga::ServiceCore &_core,
-		      std::tr1::shared_ptr<xmlDoc> _doc,
+		      shared_ptr<xmlDoc> _doc,
 		      OPENLDAP::BookInfo _bookinfo):
   saslform(NULL), core(_core), doc(_doc), name_node(NULL),
   uri_node(NULL), authcID_node(NULL), password_node(NULL),
