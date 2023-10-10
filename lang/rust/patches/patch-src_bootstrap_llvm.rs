$NetBSD: patch-src_bootstrap_llvm.rs,v 1.2 2023/10/10 13:12:33 pin Exp $

Add NetBSD to the list of riscv's which don't need -latomic.

--- src/bootstrap/llvm.rs.orig	2023-05-31 19:28:10.000000000 +0000
+++ src/bootstrap/llvm.rs
@@ -379,7 +379,7 @@ impl Step for Llvm {
             cfg.define("LLVM_LINK_LLVM_DYLIB", "ON");
         }
 
-        if target.starts_with("riscv") && !target.contains("freebsd") && !target.contains("openbsd")
+        if target.starts_with("riscv") && !target.contains("freebsd") && !target.contains("openbsd") && !target.contains("netbsd")
         {
             // RISC-V GCC erroneously requires linking against
             // `libatomic` when using 1-byte and 2-byte C++
