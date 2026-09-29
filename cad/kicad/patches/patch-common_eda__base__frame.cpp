$NetBSD: patch-common_eda__base__frame.cpp,v 1.1 2026/09/29 16:11:56 bouyer Exp $

Add NetBSD support.

--- common/eda_base_frame.cpp.orig	2026-05-05 16:34:51.211225353 +0000
+++ common/eda_base_frame.cpp
@@ -1405,7 +1405,7 @@ void EDA_BASE_FRAME::ShowPreferences( wx
                     return new PANEL_MOUSE_SETTINGS( aParent );
                 }, _( "Mouse and Touchpad" ) );
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
         book->AddLazyPage(
                 [] ( wxWindow* aParent ) -> wxWindow*
                 {
