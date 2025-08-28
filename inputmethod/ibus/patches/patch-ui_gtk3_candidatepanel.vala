$NetBSD: patch-ui_gtk3_candidatepanel.vala,v 1.1 2025/08/28 12:08:47 tsutsui Exp $

- apply upstream fix for "Candidate panel remains on the screen" problem:
  https://github.com/ibus/ibus/issues/2780

--- ui/gtk3/candidatepanel.vala.orig	2025-04-08 12:57:26.000000000 +0000
+++ ui/gtk3/candidatepanel.vala
@@ -214,7 +214,6 @@ public class CandidatePanel : Gtk.Box{
         m_set_preedit_text_id =
                 Timeout.add(100,
                             () => {
-                                //warning("test set_preedit_text_real");
                                 m_set_preedit_text_id = 0;
                                 set_preedit_text_real(text, cursor);
                                 return Source.REMOVE;
@@ -480,7 +479,11 @@ public class CandidatePanel : Gtk.Box{
     }
 
     public new void show() {
-        m_toplevel.show_all();
+        // m_toplevel.show_all() changes m_candidate_area.get_visible()
+        // in update_real() so show() is just used. Using no_show_all
+        // property for m_candidate_area would introduce the more
+        // complicated logic.
+        m_toplevel.show();
     }
 
     public new void hide() {
