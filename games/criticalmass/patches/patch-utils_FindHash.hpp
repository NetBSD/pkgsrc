$NetBSD: patch-utils_FindHash.hpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

Incomplete.

--- utils/FindHash.hpp.orig	2013-04-30 12:15:10.000000000 +0000
+++ utils/FindHash.hpp
@@ -18,9 +18,9 @@
 template< class _KeyT, class _ValT >
 _ValT* findHash( 
     _KeyT &trigger, 
-    hash_map< _KeyT, _ValT*, hash<_KeyT>, equal_to<_KeyT> > & hashMap )
+    hash_map< _KeyT, _ValT*, ::HASH_NAMESPACE::hash<_KeyT>, equal_to<_KeyT> > & hashMap )
 {
-    typename hash_map< _KeyT, _ValT*, hash<_KeyT> >::const_iterator ci;
+    typename hash_map< _KeyT, _ValT*, ::HASH_NAMESPACE::hash<_KeyT> >::const_iterator ci;
     ci = hashMap.find( trigger);
     if( ci == hashMap.end())
     {
@@ -33,9 +33,24 @@ _ValT* findHash( 
 template< class _KeyT, class _ValT >
 _ValT* findHash( 
     const _KeyT &trigger, 
-    hash_map< _KeyT, _ValT*, hash<_KeyT>, equal_to<_KeyT> > & hashMap )
+    hash_map< _KeyT, _ValT*, ::HASH_NAMESPACE::hash<_KeyT>, equal_to<_KeyT> > & hashMap )
 {
-    typename hash_map< const _KeyT, _ValT*, hash<const _KeyT> >::const_iterator ci;
+    typename hash_map< const _KeyT, _ValT*, ::HASH_NAMESPACE::hash<const _KeyT> >::const_iterator ci;
+    ci = hashMap.find( trigger);
+    if( ci == hashMap.end())
+    {
+        return 0;
+    }
+
+    return ci->second;
+}
+
+template< class _KeyT, class _ValT >
+_ValT* findHash( 
+    const _KeyT &trigger, 
+    hash_map< const _KeyT, _ValT*, ::HASH_NAMESPACE::hash<const _KeyT>, equal_to<const _KeyT> > & hashMap )
+{
+    typename hash_map< const _KeyT, _ValT*, ::HASH_NAMESPACE::hash<const _KeyT> >::const_iterator ci;
     ci = hashMap.find( trigger);
     if( ci == hashMap.end())
     {
