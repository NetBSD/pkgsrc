$NetBSD: patch-vendor_net2_src_ext.rs,v 1.3 2021/01/01 20:44:48 he Exp $

It looks like NetBSD doesn't need the same tweak as OpenBSD
to use SO_KEEPALIVE instead of TCP_KEEPIDLE when specifying
TCP-layer keepalive value.

--- vendor/net2/src/ext.rs.orig	2020-11-16 14:27:49.000000000 +0000
+++ vendor/net2/src/ext.rs
@@ -668,7 +668,7 @@ impl<T: AsRawSocket> AsSock for T {
 cfg_if! {
     if #[cfg(any(target_os = "macos", target_os = "ios"))] {
         use libc::TCP_KEEPALIVE as KEEPALIVE_OPTION;
-    } else if #[cfg(any(target_os = "haiku", target_os = "netbsd", target_os = "openbsd"))] {
+    } else if #[cfg(any(target_os = "haiku", target_os = "openbsd"))] {
         use libc::SO_KEEPALIVE as KEEPALIVE_OPTION;
     } else if #[cfg(unix)] {
         use libc::TCP_KEEPIDLE as KEEPALIVE_OPTION;
