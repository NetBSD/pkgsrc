$NetBSD: patch-src_tools_cargo_src_cargo_core_profiles.rs,v 1.10 2022/05/25 21:31:26 he Exp $

Turn off incremental builds for sparc64, ref.
https://sources.debian.org/patches/cargo/0.29.0-1/2007_sparc64_disable_incremental_build.patch/

--- src/tools/cargo/src/cargo/core/profiles.rs.orig	2018-10-24 20:01:28.000000000 +0000
+++ src/tools/cargo/src/cargo/core/profiles.rs
@@ -754,6 +754,9 @@ impl Profile {
             debuginfo: Some(2),
             debug_assertions: true,
             overflow_checks: true,
+            #[cfg(target_arch = "sparc64")]
+            incremental: false,
+            #[cfg(not(target_arch = "sparc64"))]
             incremental: true,
             ..Profile::default()
         }
