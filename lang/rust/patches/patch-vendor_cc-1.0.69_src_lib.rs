$NetBSD: patch-vendor_cc-1.0.69_src_lib.rs,v 1.1 2022/08/30 19:22:17 he Exp $

Add aarch64_be-unknown-netbsd.

--- vendor/cc-1.0.69/src/lib.rs.orig	2022-04-04 11:10:55.000000000 +0000
+++ vendor/cc-1.0.69/src/lib.rs
@@ -2382,6 +2382,7 @@ impl Build {
             "aarch64-unknown-linux-gnu" => Some("aarch64-linux-gnu"),
             "aarch64-unknown-linux-musl" => Some("aarch64-linux-musl"),
             "aarch64-unknown-netbsd" => Some("aarch64--netbsd"),
+	    "aarch64_be-unknown-netbsd" => Some("aarch64--netbsd"),
             "arm-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
             "armv4t-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
             "armv5te-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
