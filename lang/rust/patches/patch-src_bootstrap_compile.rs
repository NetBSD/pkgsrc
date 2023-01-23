$NetBSD: patch-src_bootstrap_compile.rs,v 1.11 2023/01/23 18:49:04 he Exp $

On Darwin, do not use @rpath for internal libraries.

--- src/bootstrap/compile.rs.orig	2022-12-12 16:02:12.000000000 +0000
+++ src/bootstrap/compile.rs
@@ -465,7 +465,7 @@ fn copy_sanitizers(
 
         if target == "x86_64-apple-darwin" || target == "aarch64-apple-darwin" {
             // Update the library’s install name to reflect that it has been renamed.
-            apple_darwin_update_library_name(&dst, &format!("@rpath/{}", &runtime.name));
+            apple_darwin_update_library_name(&dst, &format!("@PREFIX@/lib/{}", &runtime.name));
             // Upon renaming the install name, the code signature of the file will invalidate,
             // so we will sign it again.
             apple_darwin_sign_file(&dst);
