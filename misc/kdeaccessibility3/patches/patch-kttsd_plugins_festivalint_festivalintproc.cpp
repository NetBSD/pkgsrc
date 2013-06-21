$NetBSD: patch-kttsd_plugins_festivalint_festivalintproc.cpp,v 1.1 2013/06/21 19:23:19 jperkin Exp $

Avoid "call of overloaded 'log(int)' is ambiguous" errors.

--- kttsd/plugins/festivalint/festivalintproc.cpp.orig	2005-10-10 14:52:49.000000000 +0000
+++ kttsd/plugins/festivalint/festivalintproc.cpp
@@ -262,8 +262,8 @@ void FestivalIntProc::synth(
             // Map 50% to 200% onto 0 to 1000.
             // slider = alpha * (log(percent)-log(50))
             // with alpha = 1000/(log(200)-log(50))
-            double alpha = 1000 / (log(200) - log(50));
-            int slider = (int)floor (0.5 + alpha * (log(time)-log(50)));
+            double alpha = 1000 / (log((float)200) - log((float)50));
+            int slider = (int)floor (0.5 + alpha * (log((float)time)-log((float)50)));
             // Center at 0.
             slider = slider - 500;
             // Map -500 to 500 onto 0.15 to -0.15.
