$NetBSD: patch-vendor_openssl-sys_build_main.rs,v 1.1 2023/01/23 18:49:04 he Exp $

Patterned after Linux and Android, on 32-bit NetBSD ports
include -latomic.  Parts of this inspired by
https://github.com/sfackler/rust-openssl/commit/a0a1d1d29263abb7c47fc2e58cef8dab13762a45

--- vendor/openssl-sys/build/main.rs.orig	2022-11-02 16:21:42.000000000 +0000
+++ vendor/openssl-sys/build/main.rs
@@ -117,6 +117,15 @@ fn main() {
     {
         println!("cargo:rustc-link-lib=dylib=atomic");
     }
+    // Patterned of the above, make sure we include -latomic
+    // on ilp32 ports (yes, this only tests the "p32" part).
+    if kind == "static"
+        && env::var("CARGO_CFG_TARGET_OS").unwrap() == "netbsd"
+        && env::var("CARGO_CFG_TARGET_POINTER_WIDTH").unwrap() == "32"
+    {
+        println!("cargo:rustc-link-lib=dylib=atomic");
+    }
+
 
     if kind == "static" && target.contains("windows") {
         println!("cargo:rustc-link-lib=dylib=gdi32");
