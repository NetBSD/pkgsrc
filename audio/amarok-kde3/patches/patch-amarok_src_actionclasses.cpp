$NetBSD: patch-amarok_src_actionclasses.cpp,v 1.1 2012/07/03 18:21:48 joerg Exp $

--- amarok/src/actionclasses.cpp.orig	2012-07-03 09:20:01.000000000 +0000
+++ amarok/src/actionclasses.cpp
@@ -168,10 +168,11 @@ Menu::instance()
     return &menu;
 }
 
+extern KAboutData aboutData;
+
 KPopupMenu*
 Menu::helpMenu( QWidget *parent ) //STATIC
 {
-    extern KAboutData aboutData;
 
     if ( s_helpMenu == 0 )
         s_helpMenu = new KHelpMenu( parent, &aboutData, Amarok::actionCollection() );
