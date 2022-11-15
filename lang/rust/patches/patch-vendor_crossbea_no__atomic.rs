$NetBSD: patch-vendor_crossbea_no__atomic.rs,v 1.1 2022/11/15 23:11:14 he Exp $

Add "mipsel-unknown-netbsd" to the list who don't have
native 64-bit atomic ops.

--- vendor/crossbeam/no_atomic.rs.orig	2022-09-19 15:35:01.000000000 +0000
+++ vendor/crossbeam/no_atomic.rs
@@ -28,6 +28,7 @@ const NO_ATOMIC_64: &[&str] = &[
     "mipsel-unknown-linux-musl",
     "mipsel-unknown-linux-uclibc",
     "mipsel-unknown-none",
+    "mipsel-unknown-netbsd",
     "mipsisa32r6-unknown-linux-gnu",
     "mipsisa32r6el-unknown-linux-gnu",
     "powerpc-unknown-linux-gnu",
