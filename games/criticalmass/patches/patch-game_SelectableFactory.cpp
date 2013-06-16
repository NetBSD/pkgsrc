$NetBSD: patch-game_SelectableFactory.cpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- game/SelectableFactory.cpp.orig	2013-06-15 10:08:14.000000000 +0000
+++ game/SelectableFactory.cpp
@@ -17,7 +17,7 @@
 hash_map< 
     const string, 
     SelectableFactory*, 
-    hash<const string>, equal_to<const string> > SelectableFactory::_sfMap;
+    HASH_NAMESPACE::hash<const string>, equal_to<const string> > SelectableFactory::_sfMap;
 
 bool SelectableFactory::_initialized = false;
 
@@ -44,7 +44,7 @@ void SelectableFactory::cleanup( void)
 {
     hash_map< const string, 
               SelectableFactory*, 
-	      hash<const string> >::const_iterator ci;
+	      HASH_NAMESPACE::hash<const string> >::const_iterator ci;
     for( ci=_sfMap.begin(); ci!=_sfMap.end(); ci++)
     {
 	SelectableFactory *sf = ci->second;
