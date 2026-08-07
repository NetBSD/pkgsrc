$NetBSD: patch-.._vendor_nix-0.24.3_src_net_if__.rs,v 1.1 2026/08/07 09:30:44 pin Exp $

https://github.com/nix-rust/nix/pull/2709

--- ../vendor/nix-0.24.3/src/net/if_.rs.orig	2026-08-07 05:37:30.314529456 +0000
+++ ../vendor/nix-0.24.3/src/net/if_.rs
@@ -42,7 +42,6 @@ libc_bitflags!(
                   target_os = "ios",
                   target_os = "linux",
                   target_os = "macos",
-                  target_os = "netbsd",
                   target_os = "illumos",
                   target_os = "solaris"))]
         #[cfg_attr(docsrs, doc(cfg(all())))]
