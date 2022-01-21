$NetBSD: patch-vendor_cc_src_lib.rs,v 1.4 2022/01/21 23:20:36 he Exp $

Add aarch64_eb.

--- vendor/cc/src/lib.rs.orig	2021-07-26 15:20:38.000000000 +0000
+++ vendor/cc/src/lib.rs
@@ -2480,6 +2480,7 @@ impl Build {
             "aarch64-unknown-linux-gnu" => Some("aarch64-linux-gnu"),
             "aarch64-unknown-linux-musl" => Some("aarch64-linux-musl"),
             "aarch64-unknown-netbsd" => Some("aarch64--netbsd"),
+            "aarch64_be-unknown-netbsd" => Some("aarch64_be--netbsd"),
             "arm-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
             "armv4t-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
             "armv5te-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
