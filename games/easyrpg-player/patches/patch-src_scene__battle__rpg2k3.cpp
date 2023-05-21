$NetBSD: patch-src_scene__battle__rpg2k3.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/scene_battle_rpg2k3.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/scene_battle_rpg2k3.cpp
@@ -468,7 +468,7 @@ void Scene_Battle_Rpg2k3::UpdateAnimatio
 						help_window->Clear();
 						int state_counter = 0;
 						for (lcf::rpg::State* state : ordered_states) {
-							std::string state_name = fmt::format("{:9s}", state->name);
+							std::string state_name = fmt::format("{:9s}", std::string(state->name));
 							help_window->AddText(state_name, state->color, Text::AlignLeft, false);
 							if (++state_counter >= 5) break;
 						}
