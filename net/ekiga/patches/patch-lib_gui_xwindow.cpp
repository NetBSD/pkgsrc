$NetBSD: patch-lib_gui_xwindow.cpp,v 1.1 2013/10/15 14:46:07 joerg Exp $

--- lib/gui/xwindow.cpp.orig	2013-10-15 12:52:21.000000000 +0000
+++ lib/gui/xwindow.cpp
@@ -270,7 +270,7 @@ XWindow::Init (Display* dp, 
   if (!_colorConverter)
     return 0;
 
-  _frameBuffer = std::tr1::shared_ptr<void> (malloc (_imageWidth * _imageHeight * _planes), free);
+  _frameBuffer = shared_ptr<void> (malloc (_imageWidth * _imageHeight * _planes), free);
 
   // detect the window manager type
   _wmType = GetWMType ();
