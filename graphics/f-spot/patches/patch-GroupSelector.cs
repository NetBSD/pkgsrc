$NetBSD: patch-GroupSelector.cs,v 1.1 2015/05/23 10:33:01 kefren Exp $

--- src/Clients/MainApp/FSpot/GroupSelector.cs.orig	2015-05-23 12:11:50.000000000 +0300
+++ src/Clients/MainApp/FSpot/GroupSelector.cs	2015-05-23 12:16:57.000000000 +0300
@@ -428,6 +428,8 @@
 
 			public Box (GroupSelector selector, int item)
 			{
+				bounds = new Gdk.Rectangle();
+				bar = new Gdk.Rectangle();
 				bounds.Height = selector.background.Height;
 				bounds.Y = selector.background.Y;
 				bounds.X = selector.BoxX (item);
