$NetBSD: patch-src_game__interpreter__map.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/game_interpreter_map.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/game_interpreter_map.cpp
@@ -406,7 +406,7 @@ bool Game_Interpreter_Map::CommandShowIn
 		);
 	}
 	else {
-		pm.PushLine(fmt::format("{} {}{} {}", greeting_1, inn_price, lcf::Data::terms.gold, greeting_2));
+		pm.PushLine(fmt::format("{} {}{} {}", std::string(greeting_1), inn_price, lcf::Data::terms.gold, std::string(greeting_2)));
 		pm.PushLine(ToString(greeting_3));
 	}
 
