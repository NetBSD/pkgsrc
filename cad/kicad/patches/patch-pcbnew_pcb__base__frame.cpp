$NetBSD: patch-pcbnew_pcb__base__frame.cpp,v 1.1 2026/09/29 16:11:57 bouyer Exp $

Add NetBSD support.

--- pcbnew/pcb_base_frame.cpp.orig	2026-05-05 16:38:44.932301106 +0000
+++ pcbnew/pcb_base_frame.cpp
@@ -71,7 +71,7 @@
 #include <tool/grid_menu.h>
 #include <ratsnest/ratsnest_view_item.h>
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 #include <spacenav/spnav_2d_plugin.h>
 #else
 #include <navlib/nl_pcbnew_plugin.h>
@@ -1044,7 +1044,7 @@ void PCB_BASE_FRAME::ActivateGalCanvas()
     {
         if( !m_spaceMouse )
         {
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
             m_spaceMouse = std::make_unique<SPNAV_2D_PLUGIN>( GetCanvas() );
             m_spaceMouse->SetScale( 0.01 );
 #else
