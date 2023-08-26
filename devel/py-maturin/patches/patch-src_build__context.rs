$NetBSD: patch-src_build__context.rs,v 1.1 2023/08/26 18:20:32 tnn Exp $

Fix wrong python wheel tag on NetBSD/evbarm.

--- src/build_context.rs.orig	2023-08-17 05:08:34.000000000 +0000
+++ src/build_context.rs
@@ -557,6 +557,17 @@ impl BuildContext {
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
             (Os::FreeBsd, _)
             // NetBSD
