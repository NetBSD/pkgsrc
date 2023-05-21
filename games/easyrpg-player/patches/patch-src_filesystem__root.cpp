$NetBSD: patch-src_filesystem__root.cpp,v 1.1 2023/05/21 06:27:31 wiz Exp $

Adapt for fmtlib 10.

--- src/filesystem_root.cpp.orig	2021-10-29 19:42:00.000000000 +0000
+++ src/filesystem_root.cpp
@@ -111,7 +111,7 @@ const Filesystem& RootFilesystem::Filesy
 
 	if (it == fs_list.end()) {
 		// Only possible to trigger via commandline or bogus code, always user/dev error -> abort
-		Output::Error("Unsupported namespace {}://{}", ns, path);
+		Output::Error("Unsupported namespace {}://{}", std::string(ns), std::string(path));
 	}
 
 	return *it->second;
