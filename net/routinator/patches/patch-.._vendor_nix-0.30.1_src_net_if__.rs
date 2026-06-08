$NetBSD: patch-.._vendor_nix-0.30.1_src_net_if__.rs,v 1.1 2026/06/08 17:18:29 he Exp $

--- ../vendor/nix-0.30.1/src/net/if_.rs.orig	2026-06-08 17:03:47.415858970 +0000
+++ ../vendor/nix-0.30.1/src/net/if_.rs
@@ -66,7 +66,6 @@ libc_bitflags!(
                   solarish,
                   apple_targets,
                   target_os = "fuchsia",
-                  target_os = "netbsd",
                   target_os = "cygwin"))]
         IFF_NOTRAILERS as IflagsType;
         /// Interface manages own routes.
