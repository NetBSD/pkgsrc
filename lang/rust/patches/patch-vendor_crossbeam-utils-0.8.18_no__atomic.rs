$NetBSD: patch-vendor_crossbeam-utils-0.8.18_no__atomic.rs,v 1.1 2024/07/15 03:32:23 wiz Exp $

Add NetBSD/mipsel to non-atomic targets.

--- vendor/crossbeam-utils-0.8.18/no_atomic.rs.orig	2024-05-03 22:53:42.558166596 +0000
+++ vendor/crossbeam-utils-0.8.18/no_atomic.rs
@@ -5,6 +5,7 @@ const NO_ATOMIC: &[&str] = &[
     "bpfeb-unknown-none",
     "bpfel-unknown-none",
     "mipsel-sony-psx",
+    "mipsel-unknown-netbsd",
     "msp430-none-elf",
     "riscv32i-unknown-none-elf",
     "riscv32im-unknown-none-elf",
