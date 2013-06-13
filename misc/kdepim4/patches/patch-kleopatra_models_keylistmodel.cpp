$NetBSD: patch-kleopatra_models_keylistmodel.cpp,v 1.1 2013/06/13 14:29:37 joerg Exp $

--- kleopatra/models/keylistmodel.cpp.orig	2013-06-12 20:30:56.000000000 +0000
+++ kleopatra/models/keylistmodel.cpp
@@ -67,10 +67,6 @@
 #include <iterator>
 #include <cassert>
 
-#ifdef __GNUC__
-#include <ext/algorithm> // for is_sorted
-#endif
-
 using namespace GpgME;
 using namespace Kleo;
 
@@ -444,9 +440,6 @@ QModelIndex FlatKeyListModel::doMapFromK
 }
 
 QList<QModelIndex> FlatKeyListModel::doAddKeys( const std::vector<Key> & keys ) {
-#ifdef __GNUC__
-    assert( __gnu_cxx::is_sorted( keys.begin(), keys.end(), _detail::ByFingerprint<std::less>() ) );
-#endif
     if ( keys.empty() )
         return QList<QModelIndex>();
 
@@ -701,9 +694,6 @@ static std::vector<Key> topological_sort
 }
 
 QList<QModelIndex> HierarchicalKeyListModel::doAddKeys( const std::vector<Key> & keys ) {
-#ifdef __GNUC__
-    assert( __gnu_cxx::is_sorted( keys.begin(), keys.end(), _detail::ByFingerprint<std::less>() ) );
-#endif
     if ( keys.empty() )
         return QList<QModelIndex>();
 
