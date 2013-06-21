$NetBSD: patch-kttsd_plugins_epos_eposproc.cpp,v 1.1 2013/06/21 19:23:19 jperkin Exp $

Avoid "call of overloaded 'log(int)' is ambiguous" errors.

--- kttsd/plugins/epos/eposproc.cpp.orig	2006-01-19 16:17:11.000000000 +0000
+++ kttsd/plugins/epos/eposproc.cpp
@@ -215,8 +215,8 @@ void EposProc::synth(
     // Map 50% to 200% onto 0 to 1000.
     // slider = alpha * (log(percent)-log(50))
     // with alpha = 1000/(log(200)-log(50))
-    double alpha = 1000 / (log(200) - log(50));
-    int slider = (int)floor (0.5 + alpha * (log(time)-log(50)));
+    double alpha = 1000 / (log((float)200) - log((float)50));
+    int slider = (int)floor (0.5 + alpha * (log((float)time)-log((float)50)));
     // Center at 0.
     slider = slider - 500;
     // Map -500 to 500 onto 45 to -45 then shift to 130 to 40 (85 midpoint).
