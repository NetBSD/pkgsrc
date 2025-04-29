$NetBSD: patch-.._vendor_mac_address-1.1.5_src_iter_mod.rs,v 1.1 2025/04/29 01:53:59 manu Exp $

Add NetBSD support, copied from pkgsrc/devel/jj
https://github.com/repnop/mac_address/pull/50

--- ../vendor/mac_address-1.1.5/src/iter/mod.rs.orig	2025-03-31 01:56:32.606084379 +0200
+++ ../vendor/mac_address-1.1.5/src/iter/mod.rs	2025-03-31 01:56:44.913524824 +0200
@@ -5,8 +5,9 @@
 #[cfg(any(
     target_os = "linux",
     target_os = "macos",
     target_os = "freebsd",
+    target_os = "netbsd",
     target_os = "openbsd"
 ))]
 #[path = "linux.rs"]
 mod internal;
