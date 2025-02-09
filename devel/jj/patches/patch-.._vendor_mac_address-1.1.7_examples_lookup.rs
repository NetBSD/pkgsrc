$NetBSD: patch-.._vendor_mac_address-1.1.7_examples_lookup.rs,v 1.1 2025/02/09 21:21:14 wiz Exp $

Add NetBSD support
https://github.com/repnop/mac_address/pull/50

--- ../vendor/mac_address-1.1.7/examples/lookup.rs.orig	2025-02-09 17:44:57.536747637 +0000
+++ ../vendor/mac_address-1.1.7/examples/lookup.rs
@@ -7,6 +7,9 @@ fn main() {
     #[cfg(target_os = "freebsd")]
     let name = "em0";
 
+    #[cfg(target_os = "netbsd")]
+    let name = "igc0";
+
     #[cfg(target_os = "openbsd")]
     let name = "fxp0";
 
