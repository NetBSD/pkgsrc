$NetBSD: patch-kooka_thumbview.h,v 1.1 2013/03/26 23:30:45 joerg Exp $

--- kooka/thumbview.h.orig	2013-03-25 10:04:28.000000000 +0000
+++ kooka/thumbview.h
@@ -54,7 +54,9 @@
 class QPixmap;
 class QListViewItem;
 class KProgress;
-class KIO::PreviewJob;
+namespace KIO {
+  class PreviewJob;
+}
 
 class ThumbView: public QVBox /* KIconView */
 {
