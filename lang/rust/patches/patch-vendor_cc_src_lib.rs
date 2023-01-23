$NetBSD: patch-vendor_cc_src_lib.rs,v 1.9 2023/01/23 18:49:04 he Exp $

Add aarch64_eb and mipsel for NetBSD.

--- vendor/cc/src/lib.rs.orig	2021-07-26 15:20:38.000000000 +0000
+++ vendor/cc/src/lib.rs
@@ -2551,6 +2551,7 @@ impl Build {
             "aarch64-unknown-linux-gnu" => Some("aarch64-linux-gnu"),
             "aarch64-unknown-linux-musl" => Some("aarch64-linux-musl"),
             "aarch64-unknown-netbsd" => Some("aarch64--netbsd"),
+            "aarch64_be-unknown-netbsd" => Some("aarch64_be--netbsd"),
             "arm-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
             "armv4t-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
             "armv5te-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
@@ -2585,6 +2586,7 @@ impl Build {
             "mips-unknown-linux-musl" => Some("mips-linux-musl"),
             "mipsel-unknown-linux-gnu" => Some("mipsel-linux-gnu"),
             "mipsel-unknown-linux-musl" => Some("mipsel-linux-musl"),
+            "mipsel-unknown-netbsd" => Some("mipsel--netbsd"),
             "mips64-unknown-linux-gnuabi64" => Some("mips64-linux-gnuabi64"),
             "mips64el-unknown-linux-gnuabi64" => Some("mips64el-linux-gnuabi64"),
             "mipsisa32r6-unknown-linux-gnu" => Some("mipsisa32r6-linux-gnu"),
