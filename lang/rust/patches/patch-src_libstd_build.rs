$NetBSD: patch-src_libstd_build.rs,v 1.4 2019/07/05 09:55:31 he Exp $

SunOS support:
 - Support PKGSRC_USE_SSP (ugly for now).
 - Add libumem support.
 - Add libexecinfo for backtrace().

--- src/libstd/build.rs.orig	2019-01-16 09:30:27.000000000 +0000
+++ src/libstd/build.rs
@@ -18,6 +18,7 @@ fn main() {
         println!("cargo:rustc-link-lib=execinfo");
         println!("cargo:rustc-link-lib=pthread");
     } else if target.contains("netbsd") {
+        println!("cargo:rustc-link-lib=execinfo");
         println!("cargo:rustc-link-lib=pthread");
         println!("cargo:rustc-link-lib=rt");
     } else if target.contains("dragonfly") || target.contains("openbsd") {
@@ -27,6 +28,9 @@ fn main() {
         println!("cargo:rustc-link-lib=posix4");
         println!("cargo:rustc-link-lib=pthread");
         println!("cargo:rustc-link-lib=resolv");
+        // pkgsrc hack until I can figure out how to pass it through properly
+        println!("cargo:rustc-link-lib=ssp");
+        println!("cargo:rustc-link-lib=umem");
     } else if target.contains("apple-darwin") {
         println!("cargo:rustc-link-lib=System");
 
