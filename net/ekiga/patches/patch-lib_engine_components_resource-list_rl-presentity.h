$NetBSD: patch-lib_engine_components_resource-list_rl-presentity.h,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/resource-list/rl-presentity.h.orig	2013-10-15 12:53:28.000000000 +0000
+++ lib/engine/components/resource-list/rl-presentity.h
@@ -39,7 +39,14 @@
 #define __RL_PRESENTITY_H__
 
 #include <libxml/tree.h>
+#include <cstddef>
+#if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+#include <memory>
+using std::shared_ptr;
+#else
 #include <tr1/memory>
+using shared_ptr;
+#endif
 
 #include "form.h"
 #include "presence-core.h"
@@ -56,7 +63,7 @@ namespace RL
 
     Presentity (Ekiga::ServiceCore &_core,
 		gmref_ptr<XCAP::Path> path_,
-		std::tr1::shared_ptr<xmlDoc> doc_,
+		shared_ptr<xmlDoc> doc_,
 		xmlNodePtr _node,
 		bool writable_);
 
@@ -101,7 +108,7 @@ namespace RL
     Ekiga::ServiceCore &services;
 
     gmref_ptr<XCAP::Path> path;
-    std::tr1::shared_ptr<xmlDoc> doc;
+    shared_ptr<xmlDoc> doc;
     xmlNodePtr node;
     bool writable;
 
