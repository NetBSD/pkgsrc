$NetBSD: patch-kbabel_kbabel_kbcataloglistviewitem.cpp,v 1.1 2013/04/30 22:34:30 joerg Exp $

--- kbabel/kbabel/kbcataloglistviewitem.cpp.orig	2013-04-30 09:54:00.000000000 +0000
+++ kbabel/kbabel/kbcataloglistviewitem.cpp
@@ -22,6 +22,7 @@
 
 #include "kbcataloglistviewitem.h"
 #include <assert.h>
+#include <algorithm>
 
 KBCatalogListViewItem::KBCatalogListViewItem(KListView* lv, KListViewItem* parent,     uint id, QString msgid, QString msgstr)
  : Super(lv, parent, "","",""), m_id(id), m_msgid(msgid), m_msgstr(msgstr)
