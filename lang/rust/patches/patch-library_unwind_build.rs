$NetBSD: patch-library_unwind_build.rs,v 1.1 2020/11/13 20:35:58 he Exp $

fix build on NetBSD HEAD-llvm. XXX there is probably a better way to do this.

--- library/unwind/build.rs.orig	2020-10-07 07:53:22.000000000 +0000
+++ library/unwind/build.rs
@@ -23,7 +23,9 @@ fn main() {
     } else if target.contains("rumprun") {
         println!("cargo:rustc-link-lib=unwind");
     } else if target.contains("netbsd") {
-        println!("cargo:rustc-link-lib=gcc_s");
+	if !env::var_os("PKGSRC_HAVE_LIBCPP").is_some() {
+            println!("cargo:rustc-link-lib=gcc_s");
+	}
     } else if target.contains("openbsd") {
         if target.contains("sparc64") {
             println!("cargo:rustc-link-lib=gcc");
