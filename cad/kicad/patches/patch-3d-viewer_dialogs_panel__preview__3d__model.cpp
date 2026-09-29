$NetBSD: patch-3d-viewer_dialogs_panel__preview__3d__model.cpp,v 1.1 2026/09/29 16:11:56 bouyer Exp $

Add NetBSD support.

--- 3d-viewer/dialogs/panel_preview_3d_model.cpp.orig	2026-05-05 16:27:04.244600413 +0000
+++ 3d-viewer/dialogs/panel_preview_3d_model.cpp
@@ -50,7 +50,7 @@
 #include <eda_3d_viewer_settings.h>
 #include <board_design_settings.h>
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include <3d_spacenav/spnav_viewer_plugin.h>
 #else
 #include <3d_navlib/nl_footprint_properties_plugin.h>
@@ -201,7 +201,7 @@ PANEL_PREVIEW_3D_MODEL::PANEL_PREVIEW_3D
 
     try
     {
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
         m_spaceMouse = std::make_unique<SPNAV_VIEWER_PLUGIN>( m_previewPane );
 #else
         m_spaceMouse = std::make_unique<NL_FOOTPRINT_PROPERTIES_PLUGIN>( m_previewPane );
