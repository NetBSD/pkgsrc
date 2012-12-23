$NetBSD: patch-src_dict.h,v 1.2 2012/12/23 03:23:20 dholland Exp $

Pick up make_pair from the correct namespace; fixes clang build.

--- src/dict.h.orig	2012-12-22 19:19:36.000000000 +0000
+++ src/dict.h
@@ -55,8 +55,8 @@ class DICT
 template <typename KEY, typename VAL>
 inline void DICT<KEY,VAL>::add(const KEY k, const VAL &v)
 {
-    std::pair<typename KEY_COLL::iterator,bool> k_pos = k_coll.insert(make_pair(k,(const VAL *) NULL));
-    std::pair<typename VAL_COLL::iterator,bool> v_pos = v_coll.insert(make_pair(v,(const KEY *) NULL));
+    std::pair<typename KEY_COLL::iterator,bool> k_pos = k_coll.insert(std::make_pair(k,(const VAL *) NULL));
+    std::pair<typename VAL_COLL::iterator,bool> v_pos = v_coll.insert(std::make_pair(v,(const KEY *) NULL));
 
     if (k_pos.second)
         k_pos.first->second = &v_pos.first->first;
@@ -114,8 +114,8 @@ class DICT<T,T>
 template <typename T>
 inline void DICT<T,T>::add(const T k, const T &v)
 {
-    std::pair<typename T_COLL::iterator,bool> k_pos = t_coll.insert(make_pair(k,(T *) NULL));
-    std::pair<typename T_COLL::iterator,bool> v_pos = t_coll.insert(make_pair(v,(T *) NULL));
+    std::pair<typename T_COLL::iterator,bool> k_pos = t_coll.insert(std::make_pair(k,(T *) NULL));
+    std::pair<typename T_COLL::iterator,bool> v_pos = t_coll.insert(std::make_pair(v,(T *) NULL));
 
     if (k_pos.second)
         k_pos.first->second = &v_pos.first->first;
