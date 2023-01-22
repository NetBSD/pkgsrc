$NetBSD: patch-vcl_source_window_window2.cxx,v 1.1 2023/01/22 17:56:04 ryoon Exp $

* Return value as double, not as int to match fingerprint.

--- vcl/source/window/window2.cxx.orig	2022-12-28 10:19:16.000000000 +0000
+++ vcl/source/window/window2.cxx
@@ -618,7 +618,7 @@ static double lcl_HandleScrollHelper( Sc
         }
 
         // compute how many quantized units to scroll
-        tools::Long magnitude = o3tl::saturating_cast<tools::Long>(abs(nN));
+        tools::Long magnitude = o3tl::saturating_cast<tools::Long>(fabs(nN));
         tools::Long change = copysign(magnitude, nN);
 
         nNewPos = nNewPos - change;
