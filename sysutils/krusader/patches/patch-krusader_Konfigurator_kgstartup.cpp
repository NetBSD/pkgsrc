$NetBSD: patch-krusader_Konfigurator_kgstartup.cpp,v 1.1 2012/12/22 02:31:33 joerg Exp $

--- krusader/Konfigurator/kgstartup.cpp.orig	2012-12-22 01:06:09.000000000 +0000
+++ krusader/Konfigurator/kgstartup.cpp
@@ -55,12 +55,14 @@ KgStartup::KgStartup( bool first, QWidge
   QStringList profileList = ProfileManager::availableProfiles( "Panel" );
   profileList.push_front( "<" + i18n( "Last session" ) + ">" );
 
-  KONFIGURATOR_NAME_VALUE_PAIR comboItems[ profileList.count() ];
+  KONFIGURATOR_NAME_VALUE_PAIR *comboItems = new KONFIGURATOR_NAME_VALUE_PAIR[ profileList.count() ];
   for(unsigned int i=0; i != profileList.count(); i++ )
     comboItems[ i ].text = comboItems[ i ].value = profileList [ i ];    
   comboItems[ 0 ].value = "";
 
   profileCombo = createComboBox( "Startup", "Starter Profile Name", comboItems[ 0 ].value, comboItems, profileList.count(), panelsGrp, false, false );
+  delete[] comboItems;
+
   profileCombo->setSizePolicy(  QSizePolicy::Expanding, QSizePolicy::Fixed);
   panelsGrid->addWidget( profileCombo, 0, 1 );
 
