$NetBSD: patch-source_gui.h,v 1.1 2012/07/03 18:46:16 joerg Exp $

--- source/gui.h.orig	2012-07-03 10:55:50.000000000 +0000
+++ source/gui.h
@@ -221,7 +221,12 @@ class GuiHost : public BasicGuiHost {
         void   savebackground ( void );
         virtual int    painticons ( void );
         virtual void   paintsmallicons ( int taste, int up );
-        void   chainiconstohost ( T icn );
+        void   chainiconstohost ( T icn ) {
+          if ( icn ) {
+             setfirsticon( (T) icn->frst() );
+             getfirsticon()->sethost ( this );
+          }
+        }
         void   runpressedmouse ( int taste );
         void   cleanup ( void ) ;    // wird zum entfernen der kleinen guiicons aufgerufen, bevor das icon ausgefhrt wird
         virtual void   restorebackground ( void );
