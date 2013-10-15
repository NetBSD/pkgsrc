$NetBSD: patch-lib_engine_components_call-history_history-contact.h,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/call-history/history-contact.h.orig	2009-09-22 14:27:35.000000000 +0000
+++ lib/engine/components/call-history/history-contact.h
@@ -38,7 +38,14 @@
 
 #include <libxml/tree.h>
 
+#include <cstddef>
+#if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using std::tr1::shared_ptr;
+#endif
 
 #include "services.h"
 #include "contact-core.h"
@@ -64,11 +71,11 @@ namespace History
   public:
 
     Contact (Ekiga::ServiceCore &_core,
-	     std::tr1::shared_ptr<xmlDoc> _doc,
+	     shared_ptr<xmlDoc> _doc,
 	     xmlNodePtr _node);
 
     Contact (Ekiga::ServiceCore &_core,
-	     std::tr1::shared_ptr<xmlDoc> _doc,
+	     shared_ptr<xmlDoc> _doc,
 	     const std::string _name,
 	     const std::string _uri,
              time_t call_start,
@@ -101,7 +108,7 @@ namespace History
 
     Ekiga::ServiceCore &core;
 
-    std::tr1::shared_ptr<xmlDoc> doc;
+    shared_ptr<xmlDoc> doc;
     xmlNodePtr node;
     std::string name;
     std::string uri;
