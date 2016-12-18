$NetBSD: patch-knetworkconf_knetworkconf_knetworkconf.cpp,v 1.2 2016/12/18 21:51:31 joerg Exp $

--- knetworkconf/knetworkconf/knetworkconf.cpp.orig	2006-07-22 08:08:14.000000000 +0000
+++ knetworkconf/knetworkconf/knetworkconf.cpp
@@ -29,7 +29,8 @@ KNetworkConf::KNetworkConf(QWidget *pare
   klvProfilesList->setAllColumnsShowFocus(true);
   klvProfilesList->setRenameable(0,true);
   klvProfilesList->setRenameable(1,true);
-  QToolTip::remove( &(QListView)klvProfilesList );
+  QListView v(klvProfilesList);
+  QToolTip::remove(&v);
   tooltip = new KProfilesListViewToolTip(klvProfilesList);
     
   //Connect signals emmitted by the backend to know when data is ready to be painted.
@@ -868,7 +869,7 @@ void KNetworkConf::addKnownHostSlot(){
 
   dlg.exec();
 
-  if (!dlg.kleIpAddress->text().isEmpty() && dlg.klbAliases->firstItem() > 0 )
+  if (!dlg.kleIpAddress->text().isEmpty() && dlg.klbAliases->firstItem())
   {
     QListViewItem * item = new QListViewItem( klvKnownHosts, 0 );
 
@@ -911,7 +912,7 @@ void KNetworkConf::editKnownHostSlot()
   dlg.exec();
 
   QString _aliases;
-  if (!dlg.kleIpAddress->text().isEmpty() && dlg.klbAliases->firstItem() > 0 )
+  if (!dlg.kleIpAddress->text().isEmpty() && dlg.klbAliases->firstItem())
   {
     QListViewItem * item = klvKnownHosts->currentItem();
 
