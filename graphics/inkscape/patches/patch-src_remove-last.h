$NetBSD: patch-src_remove-last.h,v 1.1 2014/01/11 17:48:52 wiz Exp $

--- src/remove-last.h.orig	2011-07-08 18:25:09.000000000 +0000
+++ src/remove-last.h
@@ -10,10 +10,9 @@ inline void remove_last(std::vector<T> &
 {
     using std::vector;
 
-    typename vector<T>::reverse_iterator i(find(seq.rbegin(), seq.rend(), elem));
+    typename vector<T>::reverse_iterator i(std::find(seq.rbegin(), seq.rend(), elem));
     g_assert( i != seq.rend() );
-    typename vector<T>::iterator ii(&*i);
-    seq.erase(ii);
+    seq.erase(i.base());
 }
 
 
