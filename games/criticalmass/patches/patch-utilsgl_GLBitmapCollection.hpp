$NetBSD: patch-utilsgl_GLBitmapCollection.hpp,v 1.1 2013/06/16 20:40:40 joerg Exp $

--- utilsgl/GLBitmapCollection.hpp.orig	2013-04-30 12:25:42.000000000 +0000
+++ utilsgl/GLBitmapCollection.hpp
@@ -133,7 +133,7 @@ protected:
     unsigned int _bitmapCount;
     float _textureSize;
 
-    hash_map< const string, BitmapInfo*, hash<const string>, equal_to<const string> > _bitmapInfoMap;
+    hash_map< const string, BitmapInfo*, ::HASH_NAMESPACE::hash<const string>, equal_to<const string> > _bitmapInfoMap;
 
 private:
     GLBitmapCollection( const GLBitmapCollection&);
