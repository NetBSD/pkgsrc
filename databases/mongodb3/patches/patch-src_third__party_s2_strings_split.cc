$NetBSD: patch-src_third__party_s2_strings_split.cc,v 1.1 2023/02/02 14:40:33 tnn Exp $

Deal with namespace conflict.

--- src/third_party/s2/strings/split.cc.orig	2020-01-08 16:30:41.000000000 +0000
+++ src/third_party/s2/strings/split.cc
@@ -156,7 +156,7 @@ struct simple_insert_iterator {
 // SplitStringToIterator{Using|AllowEmpty}().
 template <typename T>
 struct simple_hash_map_iterator {
-  typedef hash_map<T, T> hashmap;
+  typedef s2_hash_map<T, T> hashmap;
   hashmap* t;
   bool even;
   typename hashmap::iterator curr;
@@ -246,8 +246,8 @@ void SplitStringAllowEmpty(const string&
 }
 
 void SplitStringToHashsetAllowEmpty(const string& full, const char* delim,
-                                    hash_set<string>* result) {
-  simple_insert_iterator<hash_set<string> > it(result);
+                                    s2_hash_set<string>* result) {
+  simple_insert_iterator<s2_hash_set<string> > it(result);
   SplitStringToIteratorAllowEmpty(full, delim, 0, it);
 }
 
@@ -258,7 +258,7 @@ void SplitStringToSetAllowEmpty(const st
 }
 
 void SplitStringToHashmapAllowEmpty(const string& full, const char* delim,
-                                    hash_map<string, string>* result) {
+                                    s2_hash_map<string, string>* result) {
   simple_hash_map_iterator<string> it(result);
   SplitStringToIteratorAllowEmpty(full, delim, 0, it);
 }
@@ -352,8 +352,8 @@ void SplitStringUsing(const string& full
 }
 
 void SplitStringToHashsetUsing(const string& full, const char* delim,
-                               hash_set<string>* result) {
-  simple_insert_iterator<hash_set<string> > it(result);
+                               s2_hash_set<string>* result) {
+  simple_insert_iterator<s2_hash_set<string> > it(result);
   SplitStringToIteratorUsing(full, delim, it);
 }
 
@@ -364,7 +364,7 @@ void SplitStringToSetUsing(const string&
 }
 
 void SplitStringToHashmapUsing(const string& full, const char* delim,
-                               hash_map<string, string>* result) {
+                               s2_hash_map<string, string>* result) {
   simple_hash_map_iterator<string> it(result);
   SplitStringToIteratorUsing(full, delim, it);
 }
