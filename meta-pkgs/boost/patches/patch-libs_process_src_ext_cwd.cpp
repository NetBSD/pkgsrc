$NetBSD: patch-libs_process_src_ext_cwd.cpp,v 1.1 2024/10/10 14:44:17 jperkin Exp $

Spell filesystem correctly.

--- libs/process/src/ext/cwd.cpp.orig	2024-10-10 13:24:36.777254793 +0000
+++ libs/process/src/ext/cwd.cpp
@@ -119,7 +119,7 @@ filesystem::path cwd(boost::process::v2:
             filesystem::path("/proc") / std::to_string(pid) / "cwd", ec
             );
 #elif defined(__sun)
-    return fileystem::canonical(
+    return filesystem::canonical(
             filesystem::path("/proc") / std::to_string(pid) / "path/cwd", ec
             );
 #endif
