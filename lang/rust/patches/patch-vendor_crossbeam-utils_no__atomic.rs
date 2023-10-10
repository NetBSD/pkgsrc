$NetBSD: patch-vendor_crossbeam-utils_no__atomic.rs,v 1.4 2023/10/10 13:12:33 pin Exp $

Add mipsel-unknown-netbsd target as not having 64-bit atomics.
Unify with crossbeam-utils-0.8.12 by removing mipsel-sony-psx.

--- vendor/crossbeam-utils/no_atomic.rs.orig	2023-07-12 05:06:31.000000000 +0000
+++ vendor/crossbeam-utils/no_atomic.rs
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
