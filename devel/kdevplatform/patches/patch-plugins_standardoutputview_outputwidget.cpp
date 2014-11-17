$NetBSD: patch-plugins_standardoutputview_outputwidget.cpp,v 1.1 2014/11/17 19:01:13 joerg Exp $

select doesn't exist.

--- plugins/standardoutputview/outputwidget.cpp.orig	2014-11-17 15:46:00.000000000 +0000
+++ plugins/standardoutputview/outputwidget.cpp
@@ -422,7 +422,6 @@ void OutputWidget::selectItem(Direction 
         ? iface->previousHighlightIndex( index )
         : iface->nextHighlightIndex( index );
 
-    kDebug() << "selecting item" << select << index << newIndex;
     activateIndex(newIndex, view, iface);
 }
 
