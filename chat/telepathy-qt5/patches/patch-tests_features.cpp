$NetBSD: patch-tests_features.cpp,v 1.1 2019/12/12 16:44:53 nros Exp $
* remove use of deprecated function
--- tests/features.cpp.orig	2019-12-10 09:46:54.250097469 +0000
+++ tests/features.cpp
@@ -13,7 +13,7 @@ QList<Feature> reverse(const QList<Featu
 {
     QList<Feature> ret(list);
     for (int k = 0; k < (list.size() / 2); k++) {
-        ret.swap(k, list.size() - (1 + k));
+        ret.swapItemsAt(k, list.size() - (1 + k));
     }
     return ret;
 }
