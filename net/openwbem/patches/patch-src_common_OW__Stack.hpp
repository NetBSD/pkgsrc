$NetBSD: patch-src_common_OW__Stack.hpp,v 1.1 2013/03/26 23:34:34 joerg Exp $

--- src/common/OW_Stack.hpp.orig	2013-03-25 15:18:00.000000000 +0000
+++ src/common/OW_Stack.hpp
@@ -54,7 +54,7 @@ public:
 	reference top() {   return this->back(); }
 	const_reference top() const {   return this->back(); }
 	void pop() { this->pop_back(); }
-	void push(const T& x) {   push_back(x); }
+	void push(const T& x) { this->push_back(x); }
 	int search(const T& x) const
 	{
 		int i = find(x);
