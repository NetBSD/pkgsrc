$NetBSD: patch-src_build__context.rs,v 1.2 2023/09/27 12:49:10 wiz Exp $

Fix wrong python wheel tag on NetBSD/evbarm.

Fix wrong python wheel tag on macOS.
https://github.com/PyO3/maturin/pull/1778

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
@@ -1150,7 +1161,21 @@ fn macosx_deployment_target(
             arm64_ver = (major, minor);
         }
     }
-    Ok((x86_64_ver, arm64_ver))
+    Ok((
+        python_macosx_target_version(x86_64_ver),
+        python_macosx_target_version(arm64_ver),
+    ))
+}
+
+#[inline]
+fn python_macosx_target_version(version: (u16, u16)) -> (u16, u16) {
+    let (major, minor) = version;
+    if major >= 11 {
+        // pip only supports (major, 0) for macOS 11+
+        (major, 0)
+    } else {
+        (major, minor)
+    }
 }
 
 pub(crate) fn rustc_macosx_target_version(target: &str) -> (u16, u16) {
@@ -1277,7 +1302,7 @@ mod test {
         );
         assert_eq!(
             macosx_deployment_target(Some("11.1"), false).unwrap(),
-            ((11, 1), (11, 1))
+            ((11, 0), (11, 0))
         );
     }
 }
