$NetBSD: patch-compiler_rustc__target_src_spec_mod.rs,v 1.15 2023/10/25 05:50:43 pin Exp $

Add i586(pentium) and mipsel NetBSD targets.

--- compiler/rustc_target/src/spec/mod.rs.orig	2021-03-23 16:15:10.000000000 +0000
+++ compiler/rustc_target/src/spec/mod.rs
@@ -1324,6 +1324,8 @@ supported_targets! {
     ("armv6-unknown-netbsd-eabihf", armv6_unknown_netbsd_eabihf),
     ("armv7-unknown-netbsd-eabihf", armv7_unknown_netbsd_eabihf),
     ("i686-unknown-netbsd", i686_unknown_netbsd),
+    ("i586-unknown-netbsd", i586_unknown_netbsd),
+    ("mipsel-unknown-netbsd", mipsel_unknown_netbsd),
     ("powerpc-unknown-netbsd", powerpc_unknown_netbsd),
     ("riscv64gc-unknown-netbsd", riscv64gc_unknown_netbsd),
     ("sparc64-unknown-netbsd", sparc64_unknown_netbsd),
