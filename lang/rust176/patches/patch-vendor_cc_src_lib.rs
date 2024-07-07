$NetBSD: patch-vendor_cc_src_lib.rs,v 1.1 2024/07/07 10:41:21 wiz Exp $

Add aarch64_be and mipsel for NetBSD.

--- vendor/cc/src/lib.rs.orig	2024-02-17 11:28:27.283394955 +0000
+++ vendor/cc/src/lib.rs
@@ -3058,6 +3058,7 @@ impl Build {
             "aarch64-unknown-linux-gnu" => Some("aarch64-linux-gnu"),
             "aarch64-unknown-linux-musl" => Some("aarch64-linux-musl"),
             "aarch64-unknown-netbsd" => Some("aarch64--netbsd"),
+            "aarch64_be-unknown-netbsd" => Some("aarch64_be--netbsd"),
             "arm-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
             "armv4t-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
             "armv5te-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
@@ -3093,6 +3094,7 @@ impl Build {
             "mips-unknown-linux-musl" => Some("mips-linux-musl"),
             "mipsel-unknown-linux-gnu" => Some("mipsel-linux-gnu"),
             "mipsel-unknown-linux-musl" => Some("mipsel-linux-musl"),
+            "mipsel-unknown-netbsd" => Some("mipsel--netbsd"),
             "mips64-unknown-linux-gnuabi64" => Some("mips64-linux-gnuabi64"),
             "mips64el-unknown-linux-gnuabi64" => Some("mips64el-linux-gnuabi64"),
             "mipsisa32r6-unknown-linux-gnu" => Some("mipsisa32r6-linux-gnu"),
