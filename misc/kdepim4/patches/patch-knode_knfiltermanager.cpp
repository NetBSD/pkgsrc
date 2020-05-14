$NetBSD: patch-knode_knfiltermanager.cpp,v 1.1 2020/05/14 19:19:56 joerg Exp $

--- knode/knfiltermanager.cpp.orig	2020-05-12 20:24:40.606084249 +0000
+++ knode/knfiltermanager.cpp
@@ -201,7 +201,7 @@ void KNFilterManager::addFilter(KNArticl
     foreach ( KNArticleFilter *filter, mFilterList )
       activeFilters << filter->id();
     int newId = 1;
-    while ( activeFilters.contains( newId ) > 0 )
+    while ( activeFilters.contains( newId ) )
       newId++;
     f->setId( newId );
   }
