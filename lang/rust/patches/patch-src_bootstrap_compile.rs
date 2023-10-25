$NetBSD: patch-src_bootstrap_compile.rs,v 1.14 2023/10/25 05:50:43 pin Exp $

On Darwin, do not use @rpath for internal libraries.

--- src/bootstrap/compile.rs.orig	2022-12-12 16:02:12.000000000 +0000
+++ src/bootstrap/compile.rs
@@ -488,7 +488,7 @@ fn copy_sanitizers(
             || target == "x86_64-apple-ios"
         {
             // Update the library’s install name to reflect that it has been renamed.
-            apple_darwin_update_library_name(&dst, &format!("@rpath/{}", &runtime.name));
+            apple_darwin_update_library_name(&dst, &format!("@PREFIX@/lib/{}", &runtime.name));
             // Upon renaming the install name, the code signature of the file will invalidate,
             // so we will sign it again.
             apple_darwin_sign_file(&dst);
