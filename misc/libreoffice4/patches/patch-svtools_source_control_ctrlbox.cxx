$NetBSD: patch-svtools_source_control_ctrlbox.cxx,v 1.1 2014/06/01 14:31:08 ryoon Exp $

--- svtools/source/control/ctrlbox.cxx.orig	2014-04-30 19:49:45.000000000 +0000
+++ svtools/source/control/ctrlbox.cxx
@@ -824,7 +824,7 @@ sal_uInt16 LineListBox::InsertEntry( con
         if ( nPos < pLineList->size() ) {
             ImpLineList::iterator it = pLineList->begin();
             ::std::advance( it, nPos );
-            pLineList->insert( it, reinterpret_cast<ImpLineListData *>(NULL) );
+            pLineList->insert( it, static_cast<ImpLineListData *>(NULL) );
         } else {
             pLineList->push_back( NULL );
         }
