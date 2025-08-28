$NetBSD: patch-ui_gtk3_panel.vala,v 1.1 2025/08/28 12:08:47 tsutsui Exp $

- apply upstream fix for "Candidate panel remains on the screen" problem:
  https://github.com/ibus/ibus/issues/2780

--- ui/gtk3/panel.vala.orig	2025-04-08 12:57:26.000000000 +0000
+++ ui/gtk3/panel.vala
@@ -214,7 +214,7 @@ class Panel : IBus.PanelService {
 
 #if USE_GDK_WAYLAND
     private CandidatePanel get_active_candidate_panel() {
-        if (m_wayland_object_path == null) {
+        if (m_is_wayland && m_wayland_object_path == null) {
             if (m_candidate_panel_x11 == null) {
                 m_candidate_panel_x11 = candidate_panel_new(true);
                 set_use_glyph_from_engine_lang();
@@ -229,7 +229,7 @@ class Panel : IBus.PanelService {
     }
 
     private Switcher get_active_switcher() {
-        if (m_wayland_object_path == null) {
+        if (m_is_wayland && m_wayland_object_path == null) {
             if (m_switcher_x11 == null)
                 m_switcher_x11 = switcher_new(true);
             return m_switcher_x11;
