$NetBSD: patch-tests_assembly_targets_targets-elf.rs,v 1.1 2025/02/23 08:53:54 he Exp $

Fix make test.

--- tests/assembly/targets/targets-elf.rs.orig	2025-02-04 13:15:03.384854786 +0000
+++ tests/assembly/targets/targets-elf.rs
@@ -276,6 +276,9 @@
 //@ revisions: mips64el_unknown_linux_muslabi64
 //@ [mips64el_unknown_linux_muslabi64] compile-flags: --target mips64el-unknown-linux-muslabi64
 //@ [mips64el_unknown_linux_muslabi64] needs-llvm-components: mips
+//@ revisions: mips64el_unknown_netbsd
+//@ [mips64el_unknown_netbsd] compile-flags: --target mips64el_unknown_netbsd-unknown-linux-muslabi64
+//@ [mips64el_unknown_netbsd] needs-llvm-components: mips
 //@ revisions: mips_unknown_linux_gnu
 //@ [mips_unknown_linux_gnu] compile-flags: --target mips-unknown-linux-gnu
 //@ [mips_unknown_linux_gnu] needs-llvm-components: mips
