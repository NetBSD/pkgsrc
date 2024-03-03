$NetBSD: patch-src_bootstrap_src_core_build__steps_compile.rs,v 1.1 2024/03/03 14:53:32 he Exp $

On Darwin, do not use @rpath for internal libraries.

--- src/bootstrap/src/core/build_steps/compile.rs.orig	2024-01-06 20:42:20.028206400 +0000
+++ src/bootstrap/src/core/build_steps/compile.rs
@@ -626,7 +626,7 @@ fn copy_sanitizers(
             || target == "x86_64-apple-ios"
         {
             // Update the library’s install name to reflect that it has been renamed.
-            apple_darwin_update_library_name(&dst, &format!("@rpath/{}", &runtime.name));
+            apple_darwin_update_library_name(&dst, &format!("@PREFIX@/lib/{}", &runtime.name));
             // Upon renaming the install name, the code signature of the file will invalidate,
             // so we will sign it again.
             apple_darwin_sign_file(&dst);
