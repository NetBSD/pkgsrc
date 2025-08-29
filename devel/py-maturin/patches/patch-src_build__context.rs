$NetBSD: patch-src_build__context.rs,v 1.4 2025/08/29 09:51:37 adam Exp $

Fix wrong python wheel tag on NetBSD/evbarm.

--- src/build_context.rs.orig	2025-08-27 11:23:56.000000000 +0000
+++ src/build_context.rs
@@ -623,6 +623,17 @@ impl BuildContext {
                     format!("macosx_{x86_64_tag}_x86_64")
                 }
             }
+            // NetBSD evbarm
+            (Os::NetBsd, Arch::Armv7L)
+            | (Os::NetBsd, Arch::Aarch64) => {
+                let release = target.get_platform_release()?;
+                format!(
+                    "{}_{}_{}",
+                    target.target_os().to_string().to_ascii_lowercase(),
+                    release,
+                    "evbarm"
+                )
+            }
             // FreeBSD
             | (Os::FreeBsd, _) => {
                 format!(
