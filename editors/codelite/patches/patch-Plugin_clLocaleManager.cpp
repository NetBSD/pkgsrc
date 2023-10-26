$NetBSD: patch-Plugin_clLocaleManager.cpp,v 1.1 2023/10/26 10:46:58 nros Exp $

Only use threads on GNU/Linux,
fixes crash on codelite startup on NetBSD

--- Plugin/clLocaleManager.cpp.orig	2023-01-11 21:18:07.000000000 +0000
+++ Plugin/clLocaleManager.cpp
@@ -53,7 +53,7 @@ void clLocaleManager::load()
         manager->CallAfter(&clLocaleManager::OnScanCompleted, d);
     };
 
-#ifdef __WXGTK__
+#ifdef __gnu_linux__
     thread thr(entry_point, this);
     thr.detach();
 #else
@@ -72,4 +72,4 @@ clLocaleManager& clLocaleManager::get()
 {
     static clLocaleManager locale_mgr;
     return locale_mgr;
-}
\ No newline at end of file
+}
