$NetBSD: patch-vendor_target-lexicon_src_targets.rs,v 1.1 2021/05/26 09:21:39 he Exp $

Add aarch64_eb for NetBSD.

--- vendor/target-lexicon/src/targets.rs.orig	2021-03-23 16:54:53.000000000 +0000
+++ vendor/target-lexicon/src/targets.rs
@@ -1267,6 +1267,7 @@ mod tests {
             "aarch64-unknown-linux-gnu",
             "aarch64-unknown-linux-musl",
             "aarch64-unknown-netbsd",
+            "aarch64_be-unknown-netbsd",
             "aarch64-unknown-none",
             "aarch64-unknown-none-softfloat",
             "aarch64-unknown-openbsd",
