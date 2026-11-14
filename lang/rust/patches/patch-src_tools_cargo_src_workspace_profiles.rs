$NetBSD: patch-src_tools_cargo_src_workspace_profiles.rs,v 1.1 2026/11/14 22:02:08 wiz Exp $

Turn off incremental builds for sparc64, ref.
https://sources.debian.org/patches/cargo/0.29.0-1/2007_sparc64_disable_incremental_build.patch/

--- src/tools/cargo/src/workspace/profiles.rs.orig	2026-10-01 18:13:16.227888121 +0000
+++ src/tools/cargo/src/workspace/profiles.rs
@@ -732,6 +732,9 @@ impl Profile {
             debuginfo: DebugInfo::Resolved(TomlDebugInfo::Full),
             debug_assertions: true,
             overflow_checks: true,
+            #[cfg(target_arch = "sparc64")]
+            incremental: false,
+            #[cfg(not(target_arch = "sparc64"))]
             incremental: true,
             ..Profile::default()
         }
