$NetBSD: patch-filesharing_advanced_kcm__sambaconf_qmultichecklistitem.cpp,v 1.1 2013/01/15 15:30:00 joerg Exp $

--- filesharing/advanced/kcm_sambaconf/qmultichecklistitem.cpp.orig	2013-01-14 21:06:31.000000000 +0000
+++ filesharing/advanced/kcm_sambaconf/qmultichecklistitem.cpp
@@ -40,7 +40,7 @@
 static const int BoxSize = 16;
 
 
-QMultiCheckListItem::QMultiCheckListItem( QListView *parent=0) :
+QMultiCheckListItem::QMultiCheckListItem( QListView *parent) :
   QListViewItem(parent) {
 }
     
