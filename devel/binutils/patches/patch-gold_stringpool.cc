$NetBSD: patch-gold_stringpool.cc,v 1.1 2015/03/24 14:23:14 joerg Exp $

--- gold/stringpool.cc.orig	2015-03-23 13:45:40.000000000 +0000
+++ gold/stringpool.cc
@@ -73,7 +73,10 @@ Stringpool_template<Stringpool_char>::re
 {
   this->key_to_offset_.reserve(n);
 
-#if defined(HAVE_TR1_UNORDERED_MAP)
+#if __cplusplus >= 201103L || defined(_LIBCPP_VERSION)
+  this->string_set_.rehash(this->string_set_.size() + n);
+  return;
+#elif defined(HAVE_TR1_UNORDERED_MAP)
   // rehash() implementation is broken in gcc 4.0.3's stl
   //this->string_set_.rehash(this->string_set_.size() + n);
   //return;
