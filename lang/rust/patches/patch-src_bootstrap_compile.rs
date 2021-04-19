$NetBSD: patch-src_bootstrap_compile.rs,v 1.2 2021/04/19 17:08:09 he Exp $

On Darwin, do not use @rpath for internal libraries.

--- src/bootstrap/compile.rs.orig	2021-02-10 17:36:44.000000000 +0000
+++ src/bootstrap/compile.rs
@@ -359,7 +359,7 @@ fn copy_sanitizers(
             // Update the library install name reflect the fact it has been renamed.
             let status = Command::new("install_name_tool")
                 .arg("-id")
-                .arg(format!("@rpath/{}", runtime.name))
+                .arg(format!("@PREFIX@/lib/{}", runtime.name))
                 .arg(&dst)
                 .status()
                 .expect("failed to execute `install_name_tool`");
