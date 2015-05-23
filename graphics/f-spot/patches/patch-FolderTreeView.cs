$NetBSD: patch-FolderTreeView.cs,v 1.1 2015/05/23 10:33:01 kefren Exp $

--- src/Clients/MainApp/FSpot.Widgets/FolderTreeView.cs.orig	2015-05-23 12:17:48.000000000 +0300
+++ src/Clients/MainApp/FSpot.Widgets/FolderTreeView.cs	2015-05-23 12:19:54.000000000 +0300
@@ -42,11 +42,11 @@
 
 			CellRendererPixbuf pixbuf_renderer = new CellRendererPixbuf ();
 			column.PackStart (pixbuf_renderer, false);
-			column.SetCellDataFunc (pixbuf_renderer, PixbufDataFunc as TreeCellDataFunc);
+			column.SetCellDataFunc (pixbuf_renderer, PixbufDataFunc);
 
 			CellRendererTextProgress folder_renderer = new CellRendererTextProgress ();
 			column.PackStart (folder_renderer, true);
-			column.SetCellDataFunc (folder_renderer, FolderDataFunc as TreeCellDataFunc);
+			column.SetCellDataFunc (folder_renderer, FolderDataFunc);
 
 			AppendColumn (column);
 
