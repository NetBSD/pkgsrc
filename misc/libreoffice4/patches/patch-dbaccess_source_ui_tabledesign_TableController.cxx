$NetBSD: patch-dbaccess_source_ui_tabledesign_TableController.cxx,v 1.1 2014/08/26 20:58:43 joerg Exp $

--- dbaccess/source/ui/tabledesign/TableController.cxx.orig	2014-08-24 19:40:15.000000000 +0000
+++ dbaccess/source/ui/tabledesign/TableController.cxx
@@ -1393,7 +1393,8 @@ void OTableController::assignTable()
                 setEditable( xMeta.is() && !xMeta->isReadOnly() && (isAlterAllowed() || isDropAllowed() || isAddAllowed()) );
                 if(!isEditable())
                 {
-                    ::std::for_each(m_vRowList.begin(),m_vRowList.end(),boost::bind( &OTableRow::SetReadOnly, _1, boost::cref( sal_True )));
+                    sal_Bool t( sal_True );
+                    ::std::for_each(m_vRowList.begin(),m_vRowList.end(),boost::bind( &OTableRow::SetReadOnly, _1, boost::cref( t )));
                 }
                 m_bNew = sal_False;
                 // be notified when the table is in disposing
