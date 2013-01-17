$NetBSD: patch-src_projects_k3baudioeditorwidget.cpp,v 1.1 2013/01/17 16:03:02 joerg Exp $

--- src/projects/k3baudioeditorwidget.cpp.orig	2013-01-16 10:43:33.000000000 +0000
+++ src/projects/k3baudioeditorwidget.cpp
@@ -671,10 +671,10 @@ void K3bAudioEditorWidget::mousePressEve
     setSelectedRange( r );
   }
   else {
-    Range* r = findRange( e->pos() );
-    d->movedRange = r;
+    Range* r2 = findRange( e->pos() );
+    d->movedRange = r2;
     d->lastMovePosition = posToMsf( e->pos().x() );
-    setSelectedRange( r );
+    setSelectedRange( r2 );
     m_draggedMarker = findMarker( e->pos() );
   }
 
