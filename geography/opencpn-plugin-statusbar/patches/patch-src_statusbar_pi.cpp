$NetBSD: patch-src_statusbar_pi.cpp,v 1.1 2018/04/15 10:00:57 bouyer Exp $
Fix memory leak

--- src/statusbar_pi.cpp.orig	2018-04-14 18:19:56.820903950 +0200
+++ src/statusbar_pi.cpp	2018-04-14 18:27:10.083280415 +0200
@@ -424,6 +424,7 @@
         if(pgc) {
             pgc->SetBrush(wxColour(color.Red(), color.Green(), color.Blue(), alpha));
             pgc->DrawRectangle(px, py, width, height);
+	    delete pgc;
         }
 #else
         dc.SetTextBackground(color);
