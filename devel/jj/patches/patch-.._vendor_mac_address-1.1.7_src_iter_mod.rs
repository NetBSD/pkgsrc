$NetBSD: patch-.._vendor_mac_address-1.1.7_src_iter_mod.rs,v 1.1 2025/02/09 21:21:14 wiz Exp $

Add NetBSD support.
https://github.com/repnop/mac_address/pull/50

--- ../vendor/mac_address-1.1.7/src/iter/mod.rs.orig	2025-02-09 17:39:36.940150956 +0000
+++ ../vendor/mac_address-1.1.7/src/iter/mod.rs
@@ -6,6 +6,7 @@ mod internal;
     target_os = "linux",
     target_os = "macos",
     target_os = "freebsd",
+    target_os = "netbsd",
     target_os = "openbsd",
     target_os = "android",
     target_os = "illumos",
