$NetBSD: patch-src_libstd_build.rs,v 1.6 2020/06/07 22:44:39 he Exp $

SunOS support:
 - Support PKGSRC_USE_SSP (ugly for now).
 - Add libexecinfo for backtrace().

--- src/libstd/build.rs.orig	2019-08-13 06:27:22.000000000 +0000
+++ src/libstd/build.rs
@@ -16,6 +16,7 @@ fn main() {
         println!("cargo:rustc-link-lib=execinfo");
         println!("cargo:rustc-link-lib=pthread");
     } else if target.contains("netbsd") {
+        println!("cargo:rustc-link-lib=execinfo");
         println!("cargo:rustc-link-lib=pthread");
         println!("cargo:rustc-link-lib=rt");
     } else if target.contains("dragonfly") || target.contains("openbsd") {
@@ -31,6 +32,8 @@ fn main() {
         println!("cargo:rustc-link-lib=pthread");
         println!("cargo:rustc-link-lib=resolv");
         println!("cargo:rustc-link-lib=nsl");
+	// pkgsrc hack until I can figure out how to pass it through properly
+	println!("cargo:rustc-link-lib=ssp");
         // Use libumem for the (malloc-compatible) allocator
         println!("cargo:rustc-link-lib=umem");
     } else if target.contains("apple-darwin") {
