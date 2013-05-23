$NetBSD: patch-apps_kmixd.cpp,v 1.3 2013/05/23 15:06:48 joerg Exp $

--- apps/kmixd.cpp.orig	2013-05-04 01:50:10.000000000 +0000
+++ apps/kmixd.cpp
@@ -156,7 +156,7 @@ void KMixD::saveBaseConfig()
       config.writeEntry( "MasterMixer", mixerMasterCard->id() );
    }
    shared_ptr<MixDevice> mdMaster = Mixer::getGlobalMasterMD();
-   if ( mdMaster != 0 ) {
+   if ( mdMaster ) {
       config.writeEntry( "MasterMixerDevice", mdMaster->id() );
    }
    QString mixerIgnoreExpression = MixerToolBox::instance()->mixerIgnoreExpression();
