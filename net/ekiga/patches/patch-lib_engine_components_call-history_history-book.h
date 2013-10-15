$NetBSD: patch-lib_engine_components_call-history_history-book.h,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/engine/components/call-history/history-book.h.orig	2013-10-15 13:03:12.000000000 +0000
+++ lib/engine/components/call-history/history-book.h
@@ -106,7 +106,7 @@ namespace History
 			  std::string message);
 
     Ekiga::ServiceCore &core;
-    std::tr1::shared_ptr<xmlDoc> doc;
+    shared_ptr<xmlDoc> doc;
   };
 
   typedef gmref_ptr<Book> BookPtr;
