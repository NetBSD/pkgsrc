$NetBSD: patch-gui_kmixdockwidget.cpp,v 1.3 2013/05/23 15:06:48 joerg Exp $

--- gui/kmixdockwidget.cpp.orig	2013-05-04 01:54:44.000000000 +0000
+++ gui/kmixdockwidget.cpp
@@ -217,7 +217,7 @@ void KMixDockWidget::updatePixmap()
 	shared_ptr<MixDevice> md = Mixer::getGlobalMasterMD();
 
     char newPixmapType;
-    if ( md == 0 )
+    if ( !md )
     {
         newPixmapType = 'e';
     }
@@ -407,7 +407,7 @@ void KMixDockWidget::contextMenuAboutToS
 void KMixDockWidget::updateDockMuteAction ( KToggleAction* dockMuteAction )
 {  
     shared_ptr<MixDevice> md = Mixer::getGlobalMasterMD();
-    if ( md != 0 && dockMuteAction != 0 )
+    if ( md && dockMuteAction != 0 )
     {
     	Volume& vol = md->playbackVolume().hasVolume() ? md->playbackVolume() : md->captureVolume();
     	bool isInactive =  vol.isCapture() ? !md->isRecSource() : md->isMuted();
