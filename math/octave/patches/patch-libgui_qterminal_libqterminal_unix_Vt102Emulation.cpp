$NetBSD: patch-libgui_qterminal_libqterminal_unix_Vt102Emulation.cpp,v 1.1 2016/02/16 04:21:40 dbj Exp $

Changes for compiling with Qt5 instead of Qt4

--- libgui/qterminal/libqterminal/unix/Vt102Emulation.cpp.orig	2015-05-23 14:21:53.000000000 +0000
+++ libgui/qterminal/libqterminal/unix/Vt102Emulation.cpp
@@ -994,7 +994,7 @@ void Vt102Emulation::sendKeyEvent( QKeyE
                                          "is missing.");
 
         reset();
-        receiveData( translatorError.toAscii().constData() , translatorError.count() );
+        receiveData( translatorError.toLatin1().constData() , translatorError.count() );
     }
 }
 
