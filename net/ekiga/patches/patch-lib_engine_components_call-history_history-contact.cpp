$NetBSD: patch-lib_engine_components_call-history_history-contact.cpp,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/call-history/history-contact.cpp.orig	2013-10-15 13:03:06.000000000 +0000
+++ lib/engine/components/call-history/history-contact.cpp
@@ -45,7 +45,7 @@
 
 
 History::Contact::Contact (Ekiga::ServiceCore &_core,
-			   std::tr1::shared_ptr<xmlDoc> _doc,
+			   shared_ptr<xmlDoc> _doc,
 			   xmlNodePtr _node):
   core(_core), doc(_doc), node(_node)
 {
@@ -102,7 +102,7 @@ History::Contact::Contact (Ekiga::Servic
 
 
 History::Contact::Contact (Ekiga::ServiceCore &_core,
-			   std::tr1::shared_ptr<xmlDoc> _doc,
+			   shared_ptr<xmlDoc> _doc,
 			   const std::string _name,
 			   const std::string _uri,
                            time_t _call_start,
