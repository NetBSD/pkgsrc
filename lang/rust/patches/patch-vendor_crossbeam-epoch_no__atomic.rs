$NetBSD: patch-vendor_crossbeam-epoch_no__atomic.rs,v 1.5 2023/10/25 05:50:43 pin Exp $

Add "mipsel-unknown-netbsd" to the list who don't have 
native 64-bit atomic ops.
Unify with crossbeam-epoch to get same after-checksum...

--- vendor/crossbeam-epoch/no_atomic.rs.orig	2023-07-12 05:06:31.000000000 +0000
+++ vendor/crossbeam-epoch/no_atomic.rs
@@ -38,10 +38,10 @@ const NO_ATOMIC_64: &[&str] = &[
     "mips-unknown-linux-musl",
     "mips-unknown-linux-uclibc",
     "mipsel-sony-psp",
-    "mipsel-sony-psx",
     "mipsel-unknown-linux-gnu",
     "mipsel-unknown-linux-musl",
     "mipsel-unknown-linux-uclibc",
+    "mipsel-unknown-netbsd",
     "mipsel-unknown-none",
     "mipsisa32r6-unknown-linux-gnu",
     "mipsisa32r6el-unknown-linux-gnu",
