$NetBSD: patch-compiler_rustc__target_src_spec_mod.rs,v 1.16 2024/03/03 14:53:32 he Exp $

Add entry for NetBSD/mips64el.

--- compiler/rustc_target/src/spec/mod.rs.orig	2024-01-13 14:20:59.236278792 +0000
+++ compiler/rustc_target/src/spec/mod.rs
@@ -1532,6 +1532,7 @@ supported_targets! {
     ("armv7-unknown-netbsd-eabihf", armv7_unknown_netbsd_eabihf),
     ("i586-unknown-netbsd", i586_unknown_netbsd),
     ("i686-unknown-netbsd", i686_unknown_netbsd),
+    ("mips64el-unknown-netbsd", mips64el_unknown_netbsd),
     ("mipsel-unknown-netbsd", mipsel_unknown_netbsd),
     ("powerpc-unknown-netbsd", powerpc_unknown_netbsd),
     ("riscv64gc-unknown-netbsd", riscv64gc_unknown_netbsd),
