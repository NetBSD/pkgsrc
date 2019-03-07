$NetBSD: patch-src_libunwind_build.rs,v 1.2 2019/03/07 20:19:11 jperkin Exp $

fix build on NetBSD HEAD-llvm. XXX there is probably a better way to do this.

--- src/libunwind/build.rs.orig	2018-12-18 23:11:17.000000000 +0000
+++ src/libunwind/build.rs
@@ -25,7 +25,9 @@ fn main() {
     } else if target.contains("rumprun") {
         println!("cargo:rustc-link-lib=unwind");
     } else if target.contains("netbsd") {
-        println!("cargo:rustc-link-lib=gcc_s");
+        if !env::var_os("PKGSRC_HAVE_LIBCPP").is_some() {
+            println!("cargo:rustc-link-lib=gcc_s");
+        }
     } else if target.contains("openbsd") {
         println!("cargo:rustc-link-lib=c++abi");
     } else if target.contains("solaris") {
