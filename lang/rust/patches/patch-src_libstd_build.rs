$NetBSD: patch-src_libstd_build.rs,v 1.1 2017/11/16 19:48:24 jperkin Exp $

SunOS support:
 - Support PKGSRC_USE_SSP (ugly for now).
 - Add libumem support.

--- src/libstd/build.rs.orig	2017-10-09 20:04:51.000000000 +0000
+++ src/libstd/build.rs
@@ -46,6 +46,9 @@ fn main() {
         println!("cargo:rustc-link-lib=posix4");
         println!("cargo:rustc-link-lib=pthread");
         println!("cargo:rustc-link-lib=resolv");
+        // pkgsrc hack until I can figure out how to pass it through properly
+        println!("cargo:rustc-link-lib=ssp");
+        println!("cargo:rustc-link-lib=umem");
     } else if target.contains("apple-darwin") {
         println!("cargo:rustc-link-lib=System");
 
