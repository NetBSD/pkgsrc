$NetBSD: patch-apps_kmixd.cpp,v 1.1 2013/05/06 14:54:57 joerg Exp $

--- apps/kmixd.cpp.orig	2013-05-04 01:50:10.000000000 +0000
+++ apps/kmixd.cpp
@@ -156,7 +156,7 @@ void KMixD::saveBaseConfig()
       config.writeEntry( "MasterMixer", mixerMasterCard->id() );
    }
    shared_ptr<MixDevice> mdMaster = Mixer::getGlobalMasterMD();
-   if ( mdMaster != 0 ) {
+   if ( mdMaster != nullptr ) {
       config.writeEntry( "MasterMixerDevice", mdMaster->id() );
    }
    QString mixerIgnoreExpression = MixerToolBox::instance()->mixerIgnoreExpression();
