$NetBSD: patch-.._vendor_mac_address-1.1.7_src_lib.rs,v 1.1 2025/02/09 21:21:14 wiz Exp $

Add NetBSD support.
https://github.com/repnop/mac_address/pull/50

--- ../vendor/mac_address-1.1.7/src/lib.rs.orig	2025-02-09 17:43:22.413932864 +0000
+++ ../vendor/mac_address-1.1.7/src/lib.rs
@@ -14,6 +14,7 @@ mod os;
     target_os = "linux",
     target_os = "macos",
     target_os = "freebsd",
+    target_os = "netbsd",
     target_os = "openbsd",
     target_os = "android",
     target_os = "illumos",
@@ -37,6 +38,7 @@ pub enum MacAddressError {
     target_os = "linux",
     target_os = "macos",
     target_os = "freebsd",
+    target_os = "netbsd",
     target_os = "openbsd",
     target_os = "android",
     target_os = "illumos",
