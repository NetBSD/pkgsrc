$NetBSD: patch-vendor_crossbeam-utils-0.8.14-no__atomic.rs,v 1.2 2023/10/25 05:50:43 pin Exp $

No 64-bit atomics on NetBSD/mipsel.

--- vendor/crossbeam-utils-0.8.14/no_atomic.rs.orig	2023-07-12 05:06:31.000000000 +0000
+++ vendor/crossbeam-utils-0.8.14/no_atomic.rs
@@ -41,6 +41,7 @@ const NO_ATOMIC_64: &[&str] = &[
     "mipsel-unknown-linux-gnu",
     "mipsel-unknown-linux-musl",
     "mipsel-unknown-linux-uclibc",
+    "mipsel-unknown-netbsd",
     "mipsel-unknown-none",
     "mipsisa32r6-unknown-linux-gnu",
     "mipsisa32r6el-unknown-linux-gnu",
