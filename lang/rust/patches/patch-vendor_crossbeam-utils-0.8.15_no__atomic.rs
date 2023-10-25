$NetBSD: patch-vendor_crossbeam-utils-0.8.15_no__atomic.rs,v 1.1 2023/10/25 05:50:43 pin Exp $

Add mipsel-unknown-netbsd target as not having 64-bit atomics.
Unify with crossbeam-utils-0.8.12 by removing mipsel-sony-psx.

--- vendor/crossbeam-utils-0.8.15/no_atomic.rs.orig	2023-08-23 22:08:20.000000000 +0000
+++ vendor/crossbeam-utils-0.8.15/no_atomic.rs
@@ -37,11 +37,11 @@ const NO_ATOMIC_64: &[&str] = &[
     "mips-unknown-linux-gnu",
     "mips-unknown-linux-musl",
     "mips-unknown-linux-uclibc",
-    "mipsel-sony-psp",
     "mipsel-sony-psx",
     "mipsel-unknown-linux-gnu",
     "mipsel-unknown-linux-musl",
     "mipsel-unknown-linux-uclibc",
+    "mipsel-unknown-netbsd",
     "mipsel-unknown-none",
     "mipsisa32r6-unknown-linux-gnu",
     "mipsisa32r6el-unknown-linux-gnu",
