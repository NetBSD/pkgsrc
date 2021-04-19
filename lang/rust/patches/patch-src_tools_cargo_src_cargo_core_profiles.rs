$NetBSD: patch-src_tools_cargo_src_cargo_core_profiles.rs,v 1.4 2021/04/19 17:08:09 he Exp $

Turn off incremental builds for sparc64, ref.
https://sources.debian.org/patches/cargo/0.29.0-1/2007_sparc64_disable_incremental_build.patch/

--- src/tools/cargo/src/cargo/core/profiles.rs.orig	2021-02-10 17:37:00.000000000 +0000
+++ src/tools/cargo/src/cargo/core/profiles.rs
@@ -695,6 +695,9 @@ impl Profile {
             debuginfo: Some(2),
             debug_assertions: true,
             overflow_checks: true,
+            #[cfg(target_arch = "sparc64")]
+            incremental: false,
+            #[cfg(not(target_arch = "sparc64"))]
             incremental: true,
             ..Profile::default()
         }
