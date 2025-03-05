$NetBSD: patch-src_hugin1_hugin_MainFrame.cpp,v 1.1 2025/03/05 06:27:43 adam Exp $

Fix crash on Darwin during startup.

--- src/hugin1/hugin/MainFrame.cpp.orig	2025-03-04 10:02:46.088652871 +0000
+++ src/hugin1/hugin/MainFrame.cpp
@@ -379,7 +379,7 @@ MainFrame::MainFrame(wxWindow* parent, H
             dc.DrawText(version, bitmap.GetWidth() - tw - 3, bitmap.GetHeight() - th - 3);
             dc.SelectObject(wxNullBitmap);
         }
-#if wxCHECK_VERSION(3,1,6)
+#if !defined(__WXMAC__) && wxCHECK_VERSION(3,1,6)
         bitmap.SetScaleFactor(GetDPIScaleFactor());
 #endif
         splash = new HuginSplashScreen(NULL, bitmap);
