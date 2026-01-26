$NetBSD: patch-.._vendor_nix-0.29.0_src_net_if__.rs,v 1.1 2026/01/26 10:30:12 pin Exp $

https://github.com/nix-rust/nix/pull/2709

--- ../vendor/nix-0.29.0/src/net/if_.rs.orig	2026-01-09 08:01:18.816659758 +0000
+++ ../vendor/nix-0.29.0/src/net/if_.rs
@@ -65,8 +65,7 @@ libc_bitflags!(
                   linux_android,
                   solarish,
                   apple_targets,
-                  target_os = "fuchsia",
-                  target_os = "netbsd"))]
+                  target_os = "fuchsia"))]
         IFF_NOTRAILERS as IflagsType;
         /// Interface manages own routes.
         #[cfg(any(target_os = "dragonfly"))]
