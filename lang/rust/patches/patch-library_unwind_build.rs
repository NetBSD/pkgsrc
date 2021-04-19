$NetBSD: patch-library_unwind_build.rs,v 1.2 2021/04/19 17:08:09 he Exp $

Fix build on NetBSD HEAD-llvm. XXX there is probably a better way to do this.

--- library/unwind/build.rs.orig	2021-02-10 17:36:44.000000000 +0000
+++ library/unwind/build.rs
@@ -21,7 +21,9 @@ fn main() {
     } else if target.contains("rumprun") {
         println!("cargo:rustc-link-lib=unwind");
     } else if target.contains("netbsd") {
-        println!("cargo:rustc-link-lib=gcc_s");
+          if !env::var_os("PKGSRC_HAVE_LIBCPP").is_some() {
+            println!("cargo:rustc-link-lib=gcc_s");
+        }
     } else if target.contains("openbsd") {
         if target.contains("sparc64") {
             println!("cargo:rustc-link-lib=gcc");
