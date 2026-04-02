$NetBSD: patch-src_bootstrap_src_core_sanity.rs,v 1.1 2026/04/02 19:06:34 wiz Exp $

Temporarily add m68k-unknown-netbsd to STAGE0_MISSING_TARGETS.
...while we bootstrap the target.

--- src/bootstrap/src/core/sanity.rs.orig	2026-03-02 23:18:25.000000000 +0000
+++ src/bootstrap/src/core/sanity.rs
@@ -38,6 +38,7 @@ pub struct Finder {
 const STAGE0_MISSING_TARGETS: &[&str] = &[
     // just a dummy comment so the list doesn't get onelined
     "riscv64im-unknown-none-elf",
+    "m68k-unknown-netbsd",
 ];
 
 /// Minimum version threshold for libstdc++ required when using prebuilt LLVM
