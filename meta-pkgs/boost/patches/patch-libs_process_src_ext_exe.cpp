$NetBSD: patch-libs_process_src_ext_exe.cpp,v 1.3 2024/12/29 14:53:14 adam Exp $

* Spell filesystem correctly.

--- libs/process/src/ext/exe.cpp.orig	2024-10-10 11:51:53.957585105 +0000
+++ libs/process/src/ext/exe.cpp
@@ -135,7 +135,7 @@ filesystem::path exe(boost::process::v2:
             filesystem::path("/proc") / std::to_string(pid) / "exe", ec
             );
 #elif defined(__sun)
-    return fileystem::canonical(
+    return filesystem::canonical(
             filesystem::path("/proc") / std::to_string(pid) / "path/a.out", ec
             );
 #endif
