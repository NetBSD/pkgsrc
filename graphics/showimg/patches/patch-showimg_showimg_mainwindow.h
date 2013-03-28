$NetBSD: patch-showimg_showimg_mainwindow.h,v 1.1 2013/03/28 21:43:08 joerg Exp $

--- showimg/showimg/mainwindow.h.orig	2013-03-28 12:13:26.000000000 +0000
+++ showimg/showimg/mainwindow.h
@@ -113,7 +113,6 @@ class KHistoryCombo;
 class KSqueezedTextLabel;
 class KMdiChildView;
 class KMdiToolViewAccessor;
-class KParts::ReadOnlyPart;
 
 class SHOWIMGCORE_EXPORT MainWindow : public KParts::DockMainWindow, public KBookmarkOwner
 {
