$NetBSD: patch-vendor_crossbeam-epoch_no__atomic.rs,v 1.3 2023/04/08 18:18:11 he Exp $

Add "mipsel-unknown-netbsd" to the list who don't have 
native 64-bit atomic ops.
Unify with crossbeam-epoch to get same after-checksum...

--- vendor/crossbeam-epoch/no_atomic.rs.orig	2022-09-19 15:35:01.000000000 +0000
+++ vendor/crossbeam-epoch/no_atomic.rs
@@ -37,10 +37,10 @@ const NO_ATOMIC_64: &[&str] = &[
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
@@ -74,7 +74,6 @@ const NO_ATOMIC_64: &[&str] = &[
 #[allow(dead_code)] // Only crossbeam-utils uses this.
 const NO_ATOMIC: &[&str] = &[
     "avr-unknown-gnu-atmega328",
-    "mipsel-sony-psx",
     "msp430-none-elf",
     "riscv32i-unknown-none-elf",
     "riscv32im-unknown-none-elf",
