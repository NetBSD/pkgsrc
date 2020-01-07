$NetBSD: patch-gui_xyconvert.cpp,v 1.1 2020/01/07 13:35:44 nros Exp $

* show icon in about window

--- gui/xyconvert.cpp.orig	2019-12-29 17:13:23.528063482 +0000
+++ gui/xyconvert.cpp
@@ -277,6 +277,7 @@ void App::OnAbout(wxCommandEvent&)
     adi.SetDescription(desc);
     adi.SetWebSite("http://xylib.sf.net/");
     adi.SetCopyright("(C) 2008-2015 Marcin Wojdyr <wojdyr@gmail.com>");
+    adi.SetIcon(wxIcon(xyconvert48_xpm));
     wxAboutBox(adi);
 }
 
