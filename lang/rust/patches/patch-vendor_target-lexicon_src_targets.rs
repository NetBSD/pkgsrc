$NetBSD: patch-vendor_target-lexicon_src_targets.rs,v 1.3 2021/09/10 15:09:32 jperkin Exp $

Add aarch64_eb for NetBSD.

--- vendor/target-lexicon/src/targets.rs.orig	2021-05-03 21:35:46.000000000 +0000
+++ vendor/target-lexicon/src/targets.rs
@@ -1277,6 +1277,7 @@ mod tests {
             "aarch64-unknown-linux-gnu_ilp32",
             "aarch64-unknown-linux-musl",
             "aarch64-unknown-netbsd",
+            "aarch64_be-unknown-netbsd",
             "aarch64-unknown-none",
             "aarch64-unknown-none-softfloat",
             "aarch64-unknown-openbsd",
