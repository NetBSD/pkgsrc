$NetBSD: patch-3d-viewer_3d__viewer_eda__3d__viewer__frame.cpp,v 1.1 2026/09/29 16:11:56 bouyer Exp $

Add NetBSD support.

--- 3d-viewer/3d_viewer/eda_3d_viewer_frame.cpp.orig	2026-05-05 16:08:02.643784359 +0000
+++ 3d-viewer/3d_viewer/eda_3d_viewer_frame.cpp
@@ -62,7 +62,7 @@
 #include <project_pcb.h>
 #include <toolbars_3d.h>
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include <spacenav/libspnav_driver.h>
 #include <3d_spacenav/spnav_viewer_plugin.h>
 #else
@@ -198,7 +198,7 @@ EDA_3D_VIEWER_FRAME::EDA_3D_VIEWER_FRAME
 
     try
     {
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
         m_spaceMouse = std::make_unique<SPNAV_VIEWER_PLUGIN>( m_canvas );
 #else
         m_spaceMouse = std::make_unique<NL_3D_VIEWER_PLUGIN>( m_canvas );
