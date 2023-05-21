$NetBSD: patch-src_dynrpg.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/dynrpg.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/dynrpg.cpp
@@ -63,7 +63,7 @@ std::string DynRpg::ParseVarArg(StringVi
 	parse_okay = true;
 	if (index >= static_cast<int>(args.size())) {
 		parse_okay = false;
-		Output::Warning("{}: Vararg {} out of range", func_name, index);
+		Output::Warning("{}: Vararg {} out of range", std::string(func_name), index);
 		return "";
 	}
 
@@ -95,7 +95,7 @@ std::string DynRpg::ParseVarArg(StringVi
 				else {
 					// $-ref out of range
 					parse_okay = false;
-					Output::Warning("{}: Vararg $-ref {} out of range", func_name, i);
+					Output::Warning("{}: Vararg $-ref {} out of range", std::string(func_name), i);
 					return "";
 				}
 
