$NetBSD: patch-src_hugin1_hugin_MainFrame.cpp,v 1.2 2025/11/19 16:00:48 adam Exp $

Fix crash on Darwin during startup.

--- src/hugin1/hugin/MainFrame.cpp.orig	2025-09-28 16:07:49.000000000 +0000
+++ src/hugin1/hugin/MainFrame.cpp
@@ -297,7 +297,9 @@ MainFrame::MainFrame(wxWindow* parent, H
             dc.DrawText(version, bitmap.GetWidth() - tw - 3, bitmap.GetHeight() - th - 3);
             dc.SelectObject(wxNullBitmap);
         }
+#if !defined(__WXMAC__)
         bitmap.SetScaleFactor(GetDPIScaleFactor());
+#endif
         splash = new HuginSplashScreen(NULL, bitmap);
     } else {
         wxLogFatalError(_("Fatal installation error\nThe file data/splash.png was not found at:") + huginApp::Get()->GetXRCPath());
