$NetBSD: patch-compiler_rustc__target_src_spec_mod.rs,v 1.18 2026/04/02 19:06:34 wiz Exp $

Add entry for NetBSD/mips64el and NetBSD/m68k

--- compiler/rustc_target/src/spec/mod.rs.orig	2026-02-11 07:30:54.000000000 +0000
+++ compiler/rustc_target/src/spec/mod.rs
@@ -1440,6 +1440,7 @@ supported_targets! {
     ("loongarch64-unknown-linux-musl", loongarch64_unknown_linux_musl),
     ("m68k-unknown-linux-gnu", m68k_unknown_linux_gnu),
     ("m68k-unknown-none-elf", m68k_unknown_none_elf),
+    ("m68k-unknown-netbsd", m68k_unknown_netbsd),
     ("csky-unknown-linux-gnuabiv2", csky_unknown_linux_gnuabiv2),
     ("csky-unknown-linux-gnuabiv2hf", csky_unknown_linux_gnuabiv2hf),
     ("mips-unknown-linux-gnu", mips_unknown_linux_gnu),
@@ -1529,6 +1530,7 @@ supported_targets! {
     ("armv7-unknown-netbsd-eabihf", armv7_unknown_netbsd_eabihf),
     ("i586-unknown-netbsd", i586_unknown_netbsd),
     ("i686-unknown-netbsd", i686_unknown_netbsd),
+    ("mips64el-unknown-netbsd", mips64el_unknown_netbsd),
     ("mipsel-unknown-netbsd", mipsel_unknown_netbsd),
     ("powerpc-unknown-netbsd", powerpc_unknown_netbsd),
     ("riscv64gc-unknown-netbsd", riscv64gc_unknown_netbsd),
