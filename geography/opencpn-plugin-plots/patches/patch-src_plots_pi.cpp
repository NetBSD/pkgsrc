$NetBSD: patch-src_plots_pi.cpp,v 1.1 2022/04/04 21:14:51 bouyer Exp $

Fix icons handling

--- src/plots_pi.cpp.orig	2022-04-04 11:20:38.672711152 +0200
+++ src/plots_pi.cpp	2022-04-04 11:22:24.085248480 +0200
@@ -76,6 +76,7 @@
     // Create the PlugIn icons
     initialize_images();
 
+#if 0
 // Create the PlugIn icons  -from shipdriver
 // loads png file for the listing panel icon
     wxFileName fn;
@@ -99,6 +100,7 @@
     else
         wxLogWarning("Climatology panel icon has NOT been loaded");
 // End of from Shipdriver	
+#endif
 
 	
     m_declination = NAN;
@@ -193,14 +195,10 @@
 }
 
 //  Converts  icon.cpp file to an image. Original process
-//wxBitmap *plots_pi::GetPlugInBitmap()
-//{
-//    return new wxBitmap(_img_plots->ConvertToImage().Copy());
-//}
-
-// Shipdriver uses the climatology_panel.png file to make the bitmap.
-wxBitmap *plots_pi::GetPlugInBitmap()  { return &m_panelBitmap; }
-// End of shipdriver process
+wxBitmap *plots_pi::GetPlugInBitmap()
+{
+    return _img_plots;
+}
 
 
 wxString plots_pi::GetCommonName()
