$NetBSD: patch-src_PdfMod_Gui_DocumentIconView.cs,v 1.1 2014/05/26 09:34:15 wiz Exp $

Fix build with mono-2.10, from git.

--- src/PdfMod/Gui/DocumentIconView.cs.orig	2011-03-03 15:51:49.000000000 +0000
+++ src/PdfMod/Gui/DocumentIconView.cs
@@ -319,7 +319,7 @@ namespace PdfMod.Gui
                 if (to_index < 0)
                     return;
 
-                var pages = args.SelectionData.Data as Hyena.Gui.DragDropList<Page>;
+                Hyena.Gui.DragDropList<Page> pages = args.SelectionData;
                 to_index -= pages.Count (p => p.Index < to_index);
                 var action = new MoveAction (document, pages, to_index);
                 action.Do ();
