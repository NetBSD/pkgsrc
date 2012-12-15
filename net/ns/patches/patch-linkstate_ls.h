$NetBSD: patch-linkstate_ls.h,v 1.1 2012/12/15 22:07:32 markd Exp $

gcc4.7 fix.

--- linkstate/ls.h.orig	2010-03-08 05:54:51.000000000 +0000
+++ linkstate/ls.h
@@ -134,7 +134,7 @@ public:
 		return ib.second ? ib.first : baseMap::end();
 	}
 
-	void eraseAll() { erase(baseMap::begin(), baseMap::end()); }
+	void eraseAll() { this->erase(baseMap::begin(), baseMap::end()); }
 	T* findPtr(Key key) {
 		iterator it = baseMap::find(key);
 		return (it == baseMap::end()) ? (T *)NULL : &((*it).second);
