$NetBSD: patch-src_libstd_build.rs,v 1.9 2020/07/08 14:46:14 jperkin Exp $

- Support PKGSRC_USE_SSP (ugly for now).
- Add libexecinfo for backtrace().

--- src/libstd/build.rs.orig	2020-06-01 15:44:16.000000000 +0000
+++ src/libstd/build.rs
@@ -16,6 +16,7 @@ fn main() {
         println!("cargo:rustc-link-lib=execinfo");
         println!("cargo:rustc-link-lib=pthread");
     } else if target.contains("netbsd") {
+        println!("cargo:rustc-link-lib=execinfo");
         println!("cargo:rustc-link-lib=pthread");
         println!("cargo:rustc-link-lib=rt");
     } else if target.contains("dragonfly") || target.contains("openbsd") {
@@ -25,12 +26,16 @@ fn main() {
         println!("cargo:rustc-link-lib=posix4");
         println!("cargo:rustc-link-lib=pthread");
         println!("cargo:rustc-link-lib=resolv");
+        println!("cargo:rustc-link-lib=nsl");
+        println!("cargo:rustc-link-lib=ssp");
+        println!("cargo:rustc-link-lib=umem");
     } else if target.contains("illumos") {
         println!("cargo:rustc-link-lib=socket");
         println!("cargo:rustc-link-lib=posix4");
         println!("cargo:rustc-link-lib=pthread");
         println!("cargo:rustc-link-lib=resolv");
         println!("cargo:rustc-link-lib=nsl");
+        println!("cargo:rustc-link-lib=ssp");
         // Use libumem for the (malloc-compatible) allocator
         println!("cargo:rustc-link-lib=umem");
     } else if target.contains("apple-darwin") {
