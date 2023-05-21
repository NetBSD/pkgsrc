$NetBSD: patch-src_enemyai.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/enemyai.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/enemyai.cpp
@@ -60,7 +60,7 @@ std::unique_ptr<AlgorithmBase> CreateAlg
 	if (Utils::StrICmp(name, RpgRtCompat::name) != 0) {
 		static bool warned = false;
 		if (!warned) {
-			Output::Debug("Invalid AutoBattle algo name `{}' falling back to {} ...", name, RpgRtCompat::name);
+			Output::Debug("Invalid AutoBattle algo name `{}' falling back to {} ...", std::string(name), RpgRtCompat::name);
 			warned = true;
 		}
 	}
