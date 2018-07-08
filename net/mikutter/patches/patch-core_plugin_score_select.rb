$NetBSD: patch-core_plugin_score_select.rb,v 1.1 2018/07/08 06:08:09 tsutsui Exp $

- pull upstream fix
  https://dev.mikutter.hachune.net/issues/1242

--- core/plugin/score/select.rb.orig	2018-06-10 15:38:30.000000000 +0000
+++ core/plugin/score/select.rb
@@ -4,6 +4,11 @@ module Plugin::Score
   extend self
 
   def score_by_score(model, target_note=model)
+    @score_cache ||= TimeLimitedStorage.new(Array, Object, 60)
+    @score_cache[[model, target_note]] ||= score_by_score_nocache(model, target_note)
+  end
+
+  def score_by_score_nocache(model, target_note=model)
     _, _, available_score_list = Plugin.filtering(:score_filter, model, target_note, Set.new)
     selected_score = choose_best_score(available_score_list)
     if selected_score &&  !selected_score.all? { |s| s.is_a?(Plugin::Score::TextNote) }
