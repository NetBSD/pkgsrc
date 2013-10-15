$NetBSD: patch-lib_engine_components_resource-list_rl-presentity.cpp,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/resource-list/rl-presentity.cpp.orig	2013-10-15 12:56:40.000000000 +0000
+++ lib/engine/components/resource-list/rl-presentity.cpp
@@ -48,7 +48,7 @@
 
 RL::Presentity::Presentity (Ekiga::ServiceCore &services_,
 			    gmref_ptr<XCAP::Path> path_,
-			    std::tr1::shared_ptr<xmlDoc> doc_,
+			    shared_ptr<xmlDoc> doc_,
 			    xmlNodePtr node_,
 			    bool writable_) :
   services(services_), doc(doc_), node(node_), writable(writable_),
