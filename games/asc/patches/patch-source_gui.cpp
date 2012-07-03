$NetBSD: patch-source_gui.cpp,v 1.1 2012/07/03 18:46:16 joerg Exp $

--- source/gui.cpp.orig	2012-07-03 10:55:47.000000000 +0000
+++ source/gui.cpp
@@ -153,16 +153,6 @@ void   GuiHost<T>::returncoordinates ( v
    }
 }
 
-template<class T> 
-void   GuiHost<T>::chainiconstohost ( T icn )
-{
-   if ( icn ) {
-      setfirsticon( (T) icn->frst() );
-      getfirsticon()->sethost ( this );
-   }
-}
-
-
 template<class T>
 void   GuiHost<T>::savebackground ( void )
 {
