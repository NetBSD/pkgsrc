$NetBSD: patch-vendor_crossbeam-epoch_no__atomic.rs,v 1.2 2023/01/23 18:49:04 he Exp $

Add "mipsel-unknown-netbsd" to the list who don't have 
native 64-bit atomic ops.

--- vendor/crossbeam-epoch/no_atomic.rs.orig	2022-09-19 15:35:01.000000000 +0000
+++ vendor/crossbeam-epoch/no_atomic.rs
@@ -36,6 +36,7 @@ const NO_ATOMIC_64: &[&str] = &[
     "mipsel-unknown-linux-musl",
     "mipsel-unknown-linux-uclibc",
     "mipsel-unknown-none",
+    "mipsel-unknown-netbsd",
     "mipsisa32r6-unknown-linux-gnu",
     "mipsisa32r6el-unknown-linux-gnu",
     "msp430-none-elf",
