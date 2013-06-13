$NetBSD: patch-kleopatra_utils_classify.cpp,v 1.1 2013/06/13 14:29:37 joerg Exp $

--- kleopatra/utils/classify.cpp.orig	2013-06-12 20:27:57.000000000 +0000
+++ kleopatra/utils/classify.cpp
@@ -43,10 +43,6 @@
 
 #include <boost/range.hpp>
 
-#ifdef __GNUC__
-# include <ext/algorithm>
-#endif
-
 #include <functional>
 
 using namespace boost;
@@ -149,10 +145,6 @@ unsigned int Kleo::classify( const QStri
 }
 
 unsigned int Kleo::classify( const QString & filename ) {
-#ifdef __GNUC__
-    assert( __gnu_cxx::is_sorted( begin( classifications ), end( classifications ), ByExtension<std::less>() ) );
-#endif
-
     const QFileInfo fi( filename );
 
     const _classification * const it = qBinaryFind( begin( classifications ), end( classifications ),
@@ -175,10 +167,6 @@ unsigned int Kleo::classify( const QStri
 }
 
 unsigned int Kleo::classifyContent( const QByteArray & data ) {
-#ifdef __GNUC__
-    assert( __gnu_cxx::is_sorted( begin( content_classifications ), end( content_classifications ), ByContent<std::less>(100) ) );
-#endif
-
     static const char beginString[] = "-----BEGIN ";
     static const QByteArrayMatcher beginMatcher( beginString );
     int pos = beginMatcher.indexIn( data );
