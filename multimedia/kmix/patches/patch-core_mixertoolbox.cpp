$NetBSD: patch-core_mixertoolbox.cpp,v 1.3 2013/05/23 15:06:48 joerg Exp $

--- core/mixertoolbox.cpp.orig	2013-05-04 01:52:48.000000000 +0000
+++ core/mixertoolbox.cpp
@@ -249,13 +249,13 @@ void MixerToolBox::initMixerInternal(Mul
 
    
     // Add a master device (if we haven't defined one yet)
-   if ( Mixer::getGlobalMasterMD(false) == 0 ) {
+   if ( !Mixer::getGlobalMasterMD(false) ) {
       // We have no master card yet. This actually only happens when there was
       // not one defined in the kmixrc.
       // So lets just set the first card as master card.
       if ( Mixer::mixers().count() > 0 ) {
     	  shared_ptr<MixDevice> master = Mixer::mixers().first()->getLocalMasterMD();
-         if ( master != 0 ) {
+         if ( master ) {
              QString controlId = master->id();
              Mixer::setGlobalMaster( Mixer::mixers().first()->id(), controlId, true);
          }
