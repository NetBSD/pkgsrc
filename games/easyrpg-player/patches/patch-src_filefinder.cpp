$NetBSD: patch-src_filefinder.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/filefinder.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/filefinder.cpp
@@ -172,7 +172,7 @@ std::string FileFinder::MakeCanonical(St
 				// Ignore, we are in root
 				--initial_deepness;
 			} else {
-				Output::Debug("Path traversal out of game directory: {}", path);
+				Output::Debug("Path traversal out of game directory: {}", std::string(path));
 			}
 		} else if (path_comp.empty() || path_comp == ".") {
 			// ignore
