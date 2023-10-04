$NetBSD: patch-src_build__context.rs,v 1.3 2023/10/04 09:43:49 adam Exp $

Fix wrong python wheel tag on NetBSD/evbarm.

--- src/build_context.rs.orig	2023-10-02 15:32:03.000000000 +0000
+++ src/build_context.rs
@@ -560,6 +560,17 @@ impl BuildContext {
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
