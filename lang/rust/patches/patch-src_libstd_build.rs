$NetBSD: patch-src_libstd_build.rs,v 1.2 2018/10/13 10:03:37 he Exp $

SunOS support:
 - Support PKGSRC_USE_SSP (ugly for now).
 - Add libumem support.
 - Add libexecinfo for backtrace().

--- src/libstd/build.rs.orig	2017-10-09 20:04:51.000000000 +0000
+++ src/libstd/build.rs
@@ -43,12 +43,16 @@ fn main() {
         println!("cargo:rustc-link-lib=pthread");
     } else if target.contains("dragonfly") || target.contains("bitrig") ||
               target.contains("netbsd") || target.contains("openbsd") {
+        println!("cargo:rustc-link-lib=execinfo");
         println!("cargo:rustc-link-lib=pthread");
     } else if target.contains("solaris") {
         println!("cargo:rustc-link-lib=socket");
         println!("cargo:rustc-link-lib=posix4");
         println!("cargo:rustc-link-lib=pthread");
         println!("cargo:rustc-link-lib=resolv");
+        // pkgsrc hack until I can figure out how to pass it through properly
+        println!("cargo:rustc-link-lib=ssp");
+        println!("cargo:rustc-link-lib=umem");
     } else if target.contains("apple-darwin") {
         println!("cargo:rustc-link-lib=System");
 
