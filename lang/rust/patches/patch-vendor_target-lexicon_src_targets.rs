$NetBSD: patch-vendor_target-lexicon_src_targets.rs,v 1.13 2024/03/03 14:53:33 he Exp $

Add aarch64_eb and mipsel for NetBSD.

--- vendor/target-lexicon/src/targets.rs.orig	2021-05-03 21:35:46.000000000 +0000
+++ vendor/target-lexicon/src/targets.rs
@@ -1526,6 +1526,7 @@ mod tests {
             "aarch64-unknown-linux-gnu_ilp32",
             "aarch64-unknown-linux-musl",
             "aarch64-unknown-netbsd",
+            "aarch64_be-unknown-netbsd",
             "aarch64-unknown-none",
             "aarch64-unknown-none-softfloat",
             "aarch64-unknown-openbsd",
@@ -1611,6 +1612,7 @@ mod tests {
             "mipsel-unknown-linux-gnu",
             "mipsel-unknown-linux-musl",
             "mipsel-unknown-linux-uclibc",
+            "mipsel-unknown-netbsd",
             "mipsel-unknown-none",
             "mipsisa32r6el-unknown-linux-gnu",
             "mipsisa32r6-unknown-linux-gnu",
