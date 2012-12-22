$NetBSD: patch-ktorrent_view_view.h,v 1.1 2012/12/22 20:02:37 joerg Exp $

--- ktorrent/view/view.h.orig	2012-12-22 19:35:16.000000000 +0000
+++ ktorrent/view/view.h
@@ -40,7 +40,6 @@ namespace kt
 	class ViewSelectionModel;
 	class ViewDelegate;
 	class Group;
-	class TorrentInterface;
 
 	class View : public QTreeView
 	{
