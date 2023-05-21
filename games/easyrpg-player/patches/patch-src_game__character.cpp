$NetBSD: patch-src_game__character.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/game_character.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/game_character.cpp
@@ -50,7 +50,7 @@ void Game_Character::SanitizeMoveRoute(S
 	const auto n = static_cast<int32_t>(mr.move_commands.size());
 	if (idx < 0 || idx > n) {
 		idx = n;
-		Output::Warning("{} {}: Save Data invalid {}={}. Fixing ...", TypeToStr(_type), name, chunk_name, idx);
+		Output::Warning("{} {}: Save Data invalid {}={}. Fixing ...", TypeToStr(_type), std::string(name), std::string(chunk_name), idx);
 	}
 }
 
