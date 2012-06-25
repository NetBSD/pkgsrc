$NetBSD: patch-knetworkconf_knetworkconf_knetworkconf.cpp,v 1.1 2012/06/25 11:30:29 joerg Exp $

--- knetworkconf/knetworkconf/knetworkconf.cpp.orig	2012-06-18 21:32:02.000000000 +0000
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
