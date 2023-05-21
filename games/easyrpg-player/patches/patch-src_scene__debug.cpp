$NetBSD: patch-src_scene__debug.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/scene_debug.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/scene_debug.cpp
@@ -548,7 +548,7 @@ void Scene_Debug::UpdateRangeListWindow(
 			if (GetStackSize() > 3) {
 				auto* event = Game_Map::GetEvent(GetFrame(1).value);
 				if (event) {
-					addItem(fmt::format("{:04d}: {}", event->GetId(), event->GetName()));
+					addItem(fmt::format("{:04d}: {}", event->GetId(), std::string(event->GetName())));
 					addItem(fmt::format("NumPages: {}", event->GetNumPages()));
 					const auto* page = event->GetActivePage();
 					const auto page_id = page ? page->ID : 0;
