$NetBSD: patch-.._vendor_mac_address-1.1.5_examples_lookup.rs,v 1.1 2025/04/29 01:53:59 manu Exp $

Add NetBSD support, copied from pkgsrc/devel/jj
https://github.com/repnop/mac_address/pull/50

--- ../vendor/mac_address-1.1.5/examples/lookup.rs.orig	2025-03-31 01:57:53.586169110 +0200
+++ ../vendor/mac_address-1.1.5/examples/lookup.rs	2025-03-31 01:58:26.119186563 +0200
@@ -6,8 +6,11 @@
 
     #[cfg(any(target_os = "freebsd"))]
     let name = "em0";
 
+    #[cfg(any(target_os = "freebsd"))]
+    let name = "igc0";
+
     #[cfg(any(target_os = "openbsd"))]
     let name = "fxp0";
 
     #[cfg(target_os = "windows")]
