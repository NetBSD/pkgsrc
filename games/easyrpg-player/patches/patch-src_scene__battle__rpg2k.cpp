$NetBSD: patch-src_scene__battle__rpg2k.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/scene_battle_rpg2k.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/scene_battle_rpg2k.cpp
@@ -1741,7 +1741,7 @@ void Scene_Battle_Rpg2k::CreateExecution
 
 	for (const auto& battler : battle_actions) {
 		if (std::count(battle_actions.begin(), battle_actions.end(), battler) > 1) {
-			Output::Warning("CreateExecutionOrder: Battler {} ({}) has multiple battle actions", battler->GetId(), battler->GetName());
+			Output::Warning("CreateExecutionOrder: Battler {} ({}) has multiple battle actions", battler->GetId(), std::string(battler->GetName()));
 			Output::Warning("Please report a bug!");
 			break;
 		}
