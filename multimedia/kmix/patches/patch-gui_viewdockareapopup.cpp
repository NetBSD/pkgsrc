$NetBSD: patch-gui_viewdockareapopup.cpp,v 1.1 2013/05/06 14:54:57 joerg Exp $

--- gui/viewdockareapopup.cpp.orig	2013-05-04 01:56:15.000000000 +0000
+++ gui/viewdockareapopup.cpp
@@ -244,12 +244,12 @@ Application: KMix (kmix), signal: Segmen
 	{
 		kDebug() << "ADD? mixerId=" << mixer->id();
 		shared_ptr<MixDevice>dockMD = mixer->getLocalMasterMD();
-		if ( dockMD == 0 && mixer->size() > 0 )
+		if ( dockMD == nullptr && mixer->size() > 0 )
 		{
 			// If we have no dock device yet, we will take the first available mixer device.
 			dockMD = (*mixer)[0];
 		}
-		if ( dockMD != 0 )
+		if ( dockMD != nullptr )
 		{
 			kDebug() << "ADD? mixerId=" << mixer->id() << ", md=" << dockMD->id();
 			if ( !dockMD->isApplicationStream() && dockMD->playbackVolume().hasVolume())
