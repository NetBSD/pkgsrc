$NetBSD: patch-vendor_target-lexicon_src_targets.rs,v 1.12 2023/10/25 05:50:43 pin Exp $

Add aarch64_eb, mipsel and riscv64gc for NetBSD.

--- vendor/target-lexicon/src/targets.rs.orig	2021-05-03 21:35:46.000000000 +0000
+++ vendor/target-lexicon/src/targets.rs
@@ -1357,6 +1357,7 @@ mod tests {
             "aarch64-unknown-linux-gnu_ilp32",
             "aarch64-unknown-linux-musl",
             "aarch64-unknown-netbsd",
+            "aarch64_be-unknown-netbsd",
             "aarch64-unknown-none",
             "aarch64-unknown-none-softfloat",
             "aarch64-unknown-openbsd",
@@ -1441,6 +1442,7 @@ mod tests {
             "mipsel-unknown-linux-gnu",
             "mipsel-unknown-linux-musl",
             "mipsel-unknown-linux-uclibc",
+            "mipsel-unknown-netbsd",
             "mipsel-unknown-none",
             "mipsisa32r6el-unknown-linux-gnu",
             "mipsisa32r6-unknown-linux-gnu",
@@ -1478,6 +1480,7 @@ mod tests {
             "riscv64gc-unknown-freebsd",
             "riscv64gc-unknown-linux-gnu",
             "riscv64gc-unknown-linux-musl",
+            "riscv64gc-unknown-netbsd",
             "riscv64gc-unknown-none-elf",
             "riscv64gc-unknown-openbsd",
             "riscv64imac-unknown-none-elf",
