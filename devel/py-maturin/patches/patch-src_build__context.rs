$NetBSD: patch-src_build__context.rs,v 1.5 2025/11/16 20:59:55 wiz Exp $

Fix wrong python wheel tag on NetBSD/evbarm.

--- src/build_context.rs.orig	2006-07-24 01:21:28.000000000 +0000
+++ src/build_context.rs
@@ -635,6 +635,17 @@ impl BuildContext {
                 let (min_sdk_major, min_sdk_minor) = iphoneos_deployment_target(env::var("IPHONEOS_DEPLOYMENT_TARGET").ok().as_deref())?;
                 format!("ios_{min_sdk_major}_{min_sdk_minor}_{arch}_{abi}")
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
