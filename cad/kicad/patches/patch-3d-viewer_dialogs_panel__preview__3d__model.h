$NetBSD: patch-3d-viewer_dialogs_panel__preview__3d__model.h,v 1.1 2026/09/29 16:11:56 bouyer Exp $

Add NetBSD support.

--- 3d-viewer/dialogs/panel_preview_3d_model.h.orig	2026-05-05 16:27:07.594181393 +0000
+++ 3d-viewer/dialogs/panel_preview_3d_model.h
@@ -63,7 +63,7 @@ class EMBEDDED_FILES;
 class BOARD;
 class BOARD_ADAPTER;
 class FOOTPRINT;
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 class SPNAV_VIEWER_PLUGIN;
 #else
 class NL_FOOTPRINT_PROPERTIES_PLUGIN;
@@ -235,7 +235,7 @@ private:
     /// The 3d viewer Render initial settings (must be saved and restored)
     EDA_3D_VIEWER_SETTINGS::RENDER_SETTINGS          m_initialRender;
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
     std::unique_ptr<SPNAV_VIEWER_PLUGIN> m_spaceMouse;
 #else
     std::unique_ptr<NL_FOOTPRINT_PROPERTIES_PLUGIN>  m_spaceMouse;
