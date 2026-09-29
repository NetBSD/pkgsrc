$NetBSD: patch-include_pcb__base__frame.h,v 1.1 2026/09/29 16:11:56 bouyer Exp $

Add NetBSD support.

--- include/pcb_base_frame.h.orig	2026-05-05 16:40:29.125456392 +0000
+++ include/pcb_base_frame.h
@@ -63,7 +63,7 @@ struct MAGNETIC_SETTINGS;
 class PROGRESS_REPORTER;
 class PCB_LAYER_BOX_SELECTOR;
 
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
 class SPNAV_2D_PLUGIN;
 #else
 class NL_PCBNEW_PLUGIN;
@@ -437,7 +437,7 @@ protected:
     PCB_ORIGIN_TRANSFORMS   m_originTransforms;
 
 private:
-#if defined(__linux__) || defined(__FreeBSD__)
+#if defined(__linux__) || defined(__FreeBSD__) || defined(__NetBSD__)
     std::unique_ptr<SPNAV_2D_PLUGIN>    m_spaceMouse;
 #else
     std::unique_ptr<NL_PCBNEW_PLUGIN>    m_spaceMouse;
