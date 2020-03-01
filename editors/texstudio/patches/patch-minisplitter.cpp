$NetBSD: patch-minisplitter.cpp,v 1.1 2020/03/01 12:48:13 markd Exp $

fs54269

--- src/minisplitter.cpp.orig	2019-12-24 11:57:23.000000000 +0000
+++ src/minisplitter.cpp
@@ -72,7 +72,6 @@ void MiniSplitterHandle::resizeEvent(QRe
     else
         setContentsMargins(0, 2, 0, 2);
     setMask(QRegion(contentsRect()));
-    QSplitterHandle::resizeEvent(event);
 }
 
 void MiniSplitterHandle::paintEvent(QPaintEvent *event)
