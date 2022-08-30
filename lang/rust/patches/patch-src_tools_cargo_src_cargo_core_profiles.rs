$NetBSD: patch-src_tools_cargo_src_cargo_core_profiles.rs,v 1.11 2022/08/30 19:22:17 he Exp $

Turn off incremental builds for sparc64, ref.
https://sources.debian.org/patches/cargo/0.29.0-1/2007_sparc64_disable_incremental_build.patch/

--- src/tools/cargo/src/cargo/core/profiles.rs.orig	2018-10-24 20:01:28.000000000 +0000
+++ src/tools/cargo/src/cargo/core/profiles.rs
@@ -643,6 +643,9 @@ impl Profile {
             debuginfo: Some(2),
             debug_assertions: true,
             overflow_checks: true,
+            #[cfg(target_arch = "sparc64")]
+            incremental: false,
+            #[cfg(not(target_arch = "sparc64"))]
             incremental: true,
             ..Profile::default()
         }
