$NetBSD: patch-lib_engine_components_local-roster_local-presentity.h,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/local-roster/local-presentity.h.orig	2013-10-15 12:53:32.000000000 +0000
+++ lib/engine/components/local-roster/local-presentity.h
@@ -40,8 +40,14 @@
 
 #include <libxml/tree.h>
 
+#include <cstddef>
+#if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
-
+using std::tr1::shared_ptr;
+#endif
 
 #include "form.h"
 #include "presence-core.h"
@@ -73,11 +79,11 @@ namespace Local
      * Constructors (and destructor)
      */
     Presentity (Ekiga::ServiceCore &_core,
-		std::tr1::shared_ptr<xmlDoc> _doc,
+		shared_ptr<xmlDoc> _doc,
 		xmlNodePtr _node);
 
     Presentity (Ekiga::ServiceCore &_core,
-		std::tr1::shared_ptr<xmlDoc> _doc,
+		shared_ptr<xmlDoc> _doc,
 		const std::string _name,
 		const std::string _uri,
 		const std::set<std::string> _groups);
@@ -179,7 +185,7 @@ namespace Local
 
     Ekiga::ServiceCore &core;
 
-    std::tr1::shared_ptr<xmlDoc> doc;
+    shared_ptr<xmlDoc> doc;
     xmlNodePtr node;
     xmlNodePtr name_node;
 
