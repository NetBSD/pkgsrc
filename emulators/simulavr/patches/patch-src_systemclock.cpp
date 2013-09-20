$NetBSD: patch-src_systemclock.cpp,v 1.1 2013/09/20 23:05:21 joerg Exp $

--- src/systemclock.cpp.orig	2013-09-20 22:35:37.000000000 +0000
+++ src/systemclock.cpp
@@ -67,7 +67,7 @@ bool MinHeap<Key, Value>::ContainsValue(
 template<typename Key, typename Value>
 void MinHeap<Key, Value>::Insert(Key k, Value v)
 {
-	resize(this->size()+1);
+	this->resize(this->size()+1);
 	for(unsigned i = this->size();;) {
 		unsigned parent = i/2;
 		if(parent == 0 || (*this)[parent-1].first < k) {
