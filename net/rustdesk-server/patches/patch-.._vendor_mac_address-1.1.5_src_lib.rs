$NetBSD: patch-.._vendor_mac_address-1.1.5_src_lib.rs,v 1.1 2025/04/29 01:53:59 manu Exp $

Add NetBSD support, copied from pkgsrc/devel/jj
https://github.com/repnop/mac_address/pull/50

--- ../vendor/mac_address-1.1.5/src/lib.rs.orig	2025-03-31 01:57:13.566264966 +0200
+++ ../vendor/mac_address-1.1.5/src/lib.rs	2025-03-31 01:57:32.149602630 +0200
@@ -13,8 +13,9 @@
 #[cfg(any(
     target_os = "linux",
     target_os = "macos",
     target_os = "freebsd",
+    target_os = "netbsd",
     target_os = "openbsd"
 ))]
 #[path = "linux.rs"]
 mod os;
@@ -34,8 +35,9 @@
 #[cfg(any(
     target_os = "linux",
     target_os = "macos",
     target_os = "freebsd",
+    target_os = "netbsd",
     target_os = "openbsd"
 ))]
 impl From<nix::Error> for MacAddressError {
     fn from(_: nix::Error) -> MacAddressError {
