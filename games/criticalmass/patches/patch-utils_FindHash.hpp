$NetBSD: patch-utils_FindHash.hpp,v 1.2 2014/01/06 17:08:20 dholland Exp $
Incomplete.

--- utils/FindHash.hpp.orig	2005-09-11 23:21:57.000000000 +0000
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
@@ -33,9 +33,9 @@ _ValT* findHash( 
 template< class _KeyT, class _ValT >
 _ValT* findHash( 
     const _KeyT &trigger, 
-    hash_map< _KeyT, _ValT*, hash<_KeyT>, equal_to<_KeyT> > & hashMap )
+    hash_map< _KeyT, _ValT*, ::HASH_NAMESPACE::hash<_KeyT>, equal_to<_KeyT> > & hashMap )
 {
-    typename hash_map< const _KeyT, _ValT*, hash<const _KeyT> >::const_iterator ci;
+    typename hash_map< const _KeyT, _ValT*, ::HASH_NAMESPACE::hash<const _KeyT> >::const_iterator ci;
     ci = hashMap.find( trigger);
     if( ci == hashMap.end())
     {
@@ -45,4 +45,21 @@ _ValT* findHash( 
     return ci->second;
 }
 
+#ifdef __clang__
+template< class _KeyT, class _ValT >
+_ValT* findHash( 
+    const _KeyT &trigger, 
+    hash_map< const _KeyT, _ValT*, ::HASH_NAMESPACE::hash<const _KeyT>, equal_to<const _KeyT> > & hashMap )
+{
+    typename hash_map< const _KeyT, _ValT*, ::HASH_NAMESPACE::hash<const _KeyT> >::const_iterator ci;
+    ci = hashMap.find( trigger);
+    if( ci == hashMap.end())
+    {
+        return 0;
+    }
+
+    return ci->second;
+}
+#endif
+
 #endif
