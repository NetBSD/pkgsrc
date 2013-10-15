$NetBSD: patch-lib_engine_components_resource-list_rl-cluster.h,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/resource-list/rl-cluster.h.orig	2013-10-15 12:56:50.000000000 +0000
+++ lib/engine/components/resource-list/rl-cluster.h
@@ -65,7 +65,7 @@ namespace RL {
   private:
 
     Ekiga::ServiceCore& core;
-    std::tr1::shared_ptr<xmlDoc> doc;
+    shared_ptr<xmlDoc> doc;
 
     void add (xmlNodePtr node);
     void add (const std::string uri,
