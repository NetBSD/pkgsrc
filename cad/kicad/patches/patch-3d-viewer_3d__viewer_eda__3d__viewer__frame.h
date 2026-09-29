$NetBSD: patch-3d-viewer_3d__viewer_eda__3d__viewer__frame.h,v 1.1 2026/09/29 16:11:56 bouyer Exp $

Add NetBSD support.

--- 3d-viewer/3d_viewer/eda_3d_viewer_frame.h.orig	2026-05-05 16:09:40.080833685 +0000
+++ 3d-viewer/3d_viewer/eda_3d_viewer_frame.h
@@ -44,7 +44,7 @@
 #define KICAD_DEFAULT_3D_DRAWFRAME_STYLE    (wxDEFAULT_FRAME_STYLE | wxWANTS_CHARS)
 
 // Forward declarations
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 class SPNAV_VIEWER_PLUGIN;
 #else
 class NL_3D_VIEWER_PLUGIN;
@@ -280,7 +280,7 @@ private:
 
     bool                           m_disable_ray_tracing;
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
     std::unique_ptr<SPNAV_VIEWER_PLUGIN> m_spaceMouse;
 #else
     std::unique_ptr<NL_3D_VIEWER_PLUGIN> m_spaceMouse;
