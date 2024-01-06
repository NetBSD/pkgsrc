$NetBSD: patch-vendor_cc_src_lib.rs,v 1.13 2024/01/06 19:00:19 he Exp $

Add aarch64_eb, mipsel and riscv64 for NetBSD.

--- vendor/cc/src/lib.rs.orig	2023-10-03 04:12:09.000000000 +0000
+++ vendor/cc/src/lib.rs
@@ -1946,6 +1946,9 @@ impl Build {
                         } else if target.contains("freebsd") && arch.starts_with("64") {
                             cmd.args.push(("-march=rv64gc").into());
                             cmd.args.push("-mabi=lp64d".into());
+                        } else if target.contains("netbsd") && arch.starts_with("64") {
+                            cmd.args.push(("-march=rv64gc").into());
+                            cmd.args.push("-mabi=lp64d".into());
                         } else if target.contains("openbsd") && arch.starts_with("64") {
                             cmd.args.push(("-march=rv64gc").into());
                             cmd.args.push("-mabi=lp64d".into());
@@ -2887,6 +2890,7 @@ impl Build {
             "aarch64-unknown-linux-gnu" => Some("aarch64-linux-gnu"),
             "aarch64-unknown-linux-musl" => Some("aarch64-linux-musl"),
             "aarch64-unknown-netbsd" => Some("aarch64--netbsd"),
+            "aarch64_be-unknown-netbsd" => Some("aarch64_be--netbsd"),
             "arm-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
             "armv4t-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
             "armv5te-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
@@ -2921,6 +2925,7 @@ impl Build {
             "mips-unknown-linux-musl" => Some("mips-linux-musl"),
             "mipsel-unknown-linux-gnu" => Some("mipsel-linux-gnu"),
             "mipsel-unknown-linux-musl" => Some("mipsel-linux-musl"),
+            "mipsel-unknown-netbsd" => Some("mipsel--netbsd"),
             "mips64-unknown-linux-gnuabi64" => Some("mips64-linux-gnuabi64"),
             "mips64el-unknown-linux-gnuabi64" => Some("mips64el-linux-gnuabi64"),
             "mipsisa32r6-unknown-linux-gnu" => Some("mipsisa32r6-linux-gnu"),
@@ -2963,6 +2968,7 @@ impl Build {
                 "riscv32-unknown-elf",
                 "riscv-none-embed",
             ]),
+            "riscv64gc-unknown-netbsd" => Some("riscv64--netbsd"),
             "riscv64gc-unknown-linux-gnu" => Some("riscv64-linux-gnu"),
             "riscv32gc-unknown-linux-gnu" => Some("riscv32-linux-gnu"),
             "riscv64gc-unknown-linux-musl" => Some("riscv64-linux-musl"),
