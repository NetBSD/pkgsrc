$NetBSD: patch-vendor_rustc-ap-rustc__target_src_spec_mod.rs,v 1.1 2021/05/26 09:21:39 he Exp $

Add aarch64_be NetBSD target.

--- vendor/rustc-ap-rustc_target/src/spec/mod.rs.orig	2021-03-23 16:54:53.000000000 +0000
+++ vendor/rustc-ap-rustc_target/src/spec/mod.rs
@@ -695,6 +695,7 @@ supported_targets! {
     ("x86_64-unknown-openbsd", x86_64_unknown_openbsd),
 
     ("aarch64-unknown-netbsd", aarch64_unknown_netbsd),
+    ("aarch64_be-unknown-netbsd", aarch64_be_unknown_netbsd),
     ("armv6-unknown-netbsd-eabihf", armv6_unknown_netbsd_eabihf),
     ("armv7-unknown-netbsd-eabihf", armv7_unknown_netbsd_eabihf),
     ("i686-unknown-netbsd", i686_unknown_netbsd),
