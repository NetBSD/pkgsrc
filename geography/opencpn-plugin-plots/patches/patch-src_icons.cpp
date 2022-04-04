$NetBSD: patch-src_icons.cpp,v 1.1 2022/04/04 21:14:51 bouyer Exp $

Fix icons handling

--- src/icons.cpp.orig	2022-04-04 11:24:07.480802638 +0200
+++ src/icons.cpp	2022-04-04 11:24:57.651441818 +0200
@@ -29,31 +29,18 @@
 		_img_plots = new wxBitmap(wxImage(sm));
 	}
 
-//    wxFileName fn;
-//    fn.SetPath(*GetpSharedDataLocation());
-//    fn.AppendDir(_T("plugins"));
-//    fn.AppendDir(_T("plots_pi"));
-//    fn.AppendDir(_T("data"));
-//    fn.SetFullName(_T("plots_pi.svg"));
-//    _svg_plots = fn.GetFullPath();
-//    fn.SetFullName(_T("plots_pi_rollover.svg"));
-//    _svg_plots_rollover = fn.GetFullPath();
-//    fn.SetFullName(_T("plots_pi_toggled.svg"));
-//    _svg_plots_toggled = fn.GetFullPath();
-    
 #ifdef PLUGIN_USE_SVG
-    wxFileName fn;
-    fn.SetPath(GetPluginDataDir("plots_pi"));
-    fn.AppendDir(_T("data"));
-    fn.SetFullName(_T("plots_pi.svg"));
-    _svg_plots = fn.GetFullPath();
-    wxLogMessage(_T("Loading toolbar icon: ") + _svg_plots); 
-    fn.SetFullName(_T("plots_pi_rollover.svg"));
-    _svg_plots_rollover = fn.GetFullPath();
-    wxLogMessage(_T("Loading toolbar icon: ") + _svg_plots_rollover); 
-    fn.SetFullName(_T("plots_pi_toggled.svg"));
-    _svg_plots_toggled = fn.GetFullPath();
-    wxLogMessage(_T("Loading toolbar icon: ") + _svg_plots_toggled);
+      wxFileName fn;
+      fn.SetPath(*GetpSharedDataLocation());
+      fn.AppendDir(_T("plugins"));
+      fn.AppendDir(_T("plots_pi"));
+      fn.AppendDir(_T("data"));
+      fn.SetFullName(_T("plots_pi.svg"));
+      _svg_plots = fn.GetFullPath();
+      fn.SetFullName(_T("plots_pi.svg"));
+      _svg_plots_rollover = fn.GetFullPath();
+      fn.SetFullName(_T("plots_pi_toggled.svg"));
+      _svg_plots_toggled = fn.GetFullPath();
 #endif
     
 	return;
