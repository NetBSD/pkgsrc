$NetBSD: patch-library_std_build.rs,v 1.1 2020/11/13 20:35:58 he Exp $

- Support PKGSRC_USE_SSP (ugly for now).
- Add libexecinfo for backtrace().

--- library/std/build.rs.orig	2020-10-07 07:53:22.000000000 +0000
+++ library/std/build.rs
@@ -20,6 +20,7 @@ fn main() {
             println!("cargo:rustc-cfg=freebsd12");
         }
     } else if target.contains("netbsd") {
+        println!("cargo:rustc-link-lib=execinfo");
         println!("cargo:rustc-link-lib=pthread");
         println!("cargo:rustc-link-lib=rt");
     } else if target.contains("dragonfly") || target.contains("openbsd") {
@@ -29,12 +30,16 @@ fn main() {
         println!("cargo:rustc-link-lib=posix4");
         println!("cargo:rustc-link-lib=pthread");
         println!("cargo:rustc-link-lib=resolv");
+	println!("cargo:rustc-link-lib=nsl");
+	println!("cargo:rustc-link-lib=ssp");
+	println!("cargo:rustc-link-lib=umem");
     } else if target.contains("illumos") {
         println!("cargo:rustc-link-lib=socket");
         println!("cargo:rustc-link-lib=posix4");
         println!("cargo:rustc-link-lib=pthread");
         println!("cargo:rustc-link-lib=resolv");
         println!("cargo:rustc-link-lib=nsl");
+	println!("cargo:rustc-link-lib=ssp");
         // Use libumem for the (malloc-compatible) allocator
         println!("cargo:rustc-link-lib=umem");
     } else if target.contains("apple-darwin") {
