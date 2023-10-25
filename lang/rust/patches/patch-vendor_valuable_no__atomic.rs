$NetBSD: patch-vendor_valuable_no__atomic.rs,v 1.4 2023/10/25 05:50:43 pin Exp $

Add mipsel-unknown-netbsd.

--- vendor/valuable/no_atomic.rs.orig	2022-09-19 15:35:03.000000000 +0000
+++ vendor/valuable/no_atomic.rs
@@ -30,6 +30,7 @@ const NO_ATOMIC_64: &[&str] = &[
     "mipsel-unknown-linux-musl",
     "mipsel-unknown-linux-uclibc",
     "mipsel-unknown-none",
+    "mipsel-unknown-netbsd",
     "mipsisa32r6-unknown-linux-gnu",
     "mipsisa32r6el-unknown-linux-gnu",
     "powerpc-unknown-freebsd",
