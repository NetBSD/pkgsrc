$NetBSD: patch-modules_speller_default_vector__hash-t.hpp,v 1.1 2025/04/15 12:31:31 tnn Exp $

Fix compile error with GCC 15:
modules/speller/default/vector_hash-t.hpp:186:43: error: 'class aspeller::VectorHashTable<Parms>' has no member named 'e' [-Wtemplate-body]
modules/speller/default/vector_hash-t.hpp:186:59: error: 'class aspeller::VectorHashTable<Parms>' has no member named '_size'

--- modules/speller/default/vector_hash-t.hpp.orig	2025-04-15 12:26:52.594455930 +0000
+++ modules/speller/default/vector_hash-t.hpp
@@ -183,7 +183,7 @@ namespace aspeller {
   template<class Parms>
   void VectorHashTable<Parms>::recalc_size() {
     size_ = 0;
-    for (iterator i = begin(); i != this->e; ++i, ++this->_size);
+    for (iterator i = begin(); i != end(); ++i, ++size_);
   }
 
 }
