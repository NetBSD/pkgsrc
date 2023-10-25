$NetBSD: patch-src_tools_cargo_src_cargo_core_profiles.rs,v 1.16 2023/10/25 05:50:43 pin Exp $

Turn off incremental builds for sparc64, ref.
https://sources.debian.org/patches/cargo/0.29.0-1/2007_sparc64_disable_incremental_build.patch/

--- src/tools/cargo/src/cargo/core/profiles.rs.orig	2023-07-12 03:33:05.000000000 +0000
+++ src/tools/cargo/src/cargo/core/profiles.rs
@@ -681,6 +681,9 @@ impl Profile {
             debuginfo: DebugInfo::Resolved(TomlDebugInfo::Full),
             debug_assertions: true,
             overflow_checks: true,
+            #[cfg(target_arch = "sparc64")]
+            incremental: false,
+            #[cfg(not(target_arch = "sparc64"))]
             incremental: true,
             ..Profile::default()
         }
