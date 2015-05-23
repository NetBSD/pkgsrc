$NetBSD: patch-GdkImageLoader.cs,v 1.1 2015/05/23 10:33:01 kefren Exp $

--- src/Clients/MainApp/FSpot.Loaders/GdkImageLoader.cs.orig	2015-05-23 12:09:54.000000000 +0300
+++ src/Clients/MainApp/FSpot.Loaders/GdkImageLoader.cs	2015-05-23 12:10:13.000000000 +0300
@@ -112,7 +112,7 @@
 		public new bool Close ()
 		{
 			lock (sync_handle) {
-				return base.Close (true);
+				return base.Close ();
 			}
 		}
 #endregion
