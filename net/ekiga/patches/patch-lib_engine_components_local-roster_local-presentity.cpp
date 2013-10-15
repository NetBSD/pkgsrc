$NetBSD: patch-lib_engine_components_local-roster_local-presentity.cpp,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/local-roster/local-presentity.cpp.orig	2013-10-15 12:55:38.000000000 +0000
+++ lib/engine/components/local-roster/local-presentity.cpp
@@ -48,7 +48,7 @@
  * Public API
  */
 Local::Presentity::Presentity (Ekiga::ServiceCore &_core,
-			       std::tr1::shared_ptr<xmlDoc> _doc,
+			       shared_ptr<xmlDoc> _doc,
 			       xmlNodePtr _node) :
   core(_core), doc(_doc), node(_node), name_node(NULL), presence("unknown")
 {
@@ -98,7 +98,7 @@ Local::Presentity::Presentity (Ekiga::Se
 
 
 Local::Presentity::Presentity (Ekiga::ServiceCore &_core,
-			       std::tr1::shared_ptr<xmlDoc> _doc,
+			       shared_ptr<xmlDoc> _doc,
 			       const std::string _name,
 			       const std::string _uri,
 			       const std::set<std::string> _groups) :
