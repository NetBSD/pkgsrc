$NetBSD: patch-src_game__interpreter.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/game_interpreter.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/game_interpreter.cpp
@@ -2102,7 +2102,7 @@ bool Game_Interpreter::CommandChangeVehi
 	Game_Vehicle* vehicle = Game_Map::GetVehicle(vehicle_id);
 
 	if (!vehicle) {
-		Output::Warning("ChangeVehicleGraphic: Invalid vehicle ID {}", vehicle_id);
+		Output::Warning("ChangeVehicleGraphic: Invalid vehicle ID {}", std::string(vehicle_id));
 		return true;
 	}
 
