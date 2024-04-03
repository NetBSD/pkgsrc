$NetBSD: patch-src_cli_self__update.rs,v 1.1 2024/04/03 03:29:54 schmonz Exp $

Put the sentinel file in a slightly more sensible place.

--- src/cli/self_update.rs.orig	2024-04-03 03:15:24.633543762 +0000
+++ src/cli/self_update.rs
@@ -105,7 +105,7 @@ impl SelfUpdate {
             .ok()
             .and_then(|p| p.parent().map(|p| p.to_path_buf()))
             .and_then(|p| p.parent().map(|p| p.to_path_buf()))
-            .map(|p| p.join("lib").join(".disable-self-update").exists())
+            .map(|p| p.join("lib").join("mise").join(".disable-self-update").exists())
             .unwrap_or_default()
     }
 }
