$NetBSD: patch-src_game__system.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/game_system.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/game_system.cpp
@@ -510,7 +510,7 @@ void Game_System::OnBgmReady(FileRequest
 	if (StringView(result->file).ends_with(".link")) {
 		// Handle Ineluki's MP3 patch
 		if (!stream) {
-			Output::Warning("Ineluki MP3: Link read error: {}", stream.GetName());
+			Output::Warning("Ineluki MP3: Link read error: {}", std::string(stream.GetName()));
 			return;
 		}
 
