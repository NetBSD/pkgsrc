$NetBSD: patch-compiler_rustc__target_src_spec_mod.rs,v 1.1 2021/04/19 17:08:09 he Exp $

Add reference to i586 / pentium NetBSD variant.

--- compiler/rustc_target/src/spec/mod.rs.orig	2021-02-10 17:36:44.000000000 +0000
+++ compiler/rustc_target/src/spec/mod.rs
@@ -551,6 +551,7 @@ supported_targets! {
     ("aarch64-unknown-netbsd", aarch64_unknown_netbsd),
     ("armv6-unknown-netbsd-eabihf", armv6_unknown_netbsd_eabihf),
     ("armv7-unknown-netbsd-eabihf", armv7_unknown_netbsd_eabihf),
+    ("i586-unknown-netbsd", i586_unknown_netbsd),
     ("i686-unknown-netbsd", i686_unknown_netbsd),
     ("powerpc-unknown-netbsd", powerpc_unknown_netbsd),
     ("sparc64-unknown-netbsd", sparc64_unknown_netbsd),
