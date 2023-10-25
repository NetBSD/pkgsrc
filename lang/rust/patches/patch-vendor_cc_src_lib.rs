$NetBSD: patch-vendor_cc_src_lib.rs,v 1.12 2023/10/25 05:50:43 pin Exp $

Add aarch64_eb, mipsel and riscv64 for NetBSD.

--- vendor/cc/src/lib.rs.orig	2021-07-26 15:20:38.000000000 +0000
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
@@ -2744,6 +2747,7 @@ impl Build {
             "aarch64-unknown-linux-gnu" => Some("aarch64-linux-gnu"),
             "aarch64-unknown-linux-musl" => Some("aarch64-linux-musl"),
             "aarch64-unknown-netbsd" => Some("aarch64--netbsd"),
+            "aarch64_be-unknown-netbsd" => Some("aarch64_be--netbsd"),
             "arm-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
             "armv4t-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
             "armv5te-unknown-linux-gnueabi" => Some("arm-linux-gnueabi"),
@@ -2778,6 +2782,7 @@ impl Build {
             "mips-unknown-linux-musl" => Some("mips-linux-musl"),
             "mipsel-unknown-linux-gnu" => Some("mipsel-linux-gnu"),
             "mipsel-unknown-linux-musl" => Some("mipsel-linux-musl"),
+            "mipsel-unknown-netbsd" => Some("mipsel--netbsd"),
             "mips64-unknown-linux-gnuabi64" => Some("mips64-linux-gnuabi64"),
             "mips64el-unknown-linux-gnuabi64" => Some("mips64el-linux-gnuabi64"),
             "mipsisa32r6-unknown-linux-gnu" => Some("mipsisa32r6-linux-gnu"),
@@ -2819,6 +2824,7 @@ impl Build {
                 "riscv32-unknown-elf",
                 "riscv-none-embed",
             ]),
+            "riscv64gc-unknown-netbsd" => Some("riscv64--netbsd"),
             "riscv64gc-unknown-linux-gnu" => Some("riscv64-linux-gnu"),
             "riscv32gc-unknown-linux-gnu" => Some("riscv32-linux-gnu"),
             "riscv64gc-unknown-linux-musl" => Some("riscv64-linux-musl"),
$NetBSD: patch-vendor_cc_src_lib.rs,v 1.12 2023/10/25 05:50:43 pin Exp $

--- vendor/cc/src/lib.rs.orig	2023-09-23 21:28:33.348998050 +0000
+++ vendor/cc/src/lib.rs
