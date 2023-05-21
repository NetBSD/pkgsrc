$NetBSD: patch-src_dynrpg.h,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/dynrpg.h.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/dynrpg.h
@@ -62,7 +62,7 @@ namespace DynRpg {
 			iss >> value;
 			parse_okay = !iss.fail();
 			if (!parse_okay) {
-				Output::Warning("{}: Arg {} ({}) is not numeric", func_name, i, args[i]);
+				Output::Warning("{}: Arg {} ({}) is not numeric", std::string(func_name), i, std::string(args[i]));
 				parse_okay = false;
 			}
 			return parse_okay;
@@ -80,7 +80,7 @@ namespace DynRpg {
 			iss >> value;
 			parse_okay = !iss.fail();
 			if (!parse_okay) {
-				Output::Warning("{}: Arg {} ({}) is not an integer", func_name, i, args[i]);
+				Output::Warning("{}: Arg {} ({}) is not an integer", std::string(func_name), i, args[i]);
 				parse_okay = false;
 			}
 			return parse_okay;
