$NetBSD: patch-src_update__check.rs,v 1.1 2026/11/18 20:33:07 wiz Exp $

Disable update check for pkgsrc.

--- src/update_check.rs.orig	2026-11-18 20:28:31.832661858 +0000
+++ src/update_check.rs
@@ -30,13 +30,7 @@ pub fn should_check() -> bool {
 const CHECK_INTERVAL_SECS: i64 = 24 * 60 * 60;
 
 pub fn should_check() -> bool {
-    if portal::is_flatpak() {
-        return false;
-    }
-
-    let now = unix_now();
-    let last = app_settings().int64("last-update-check");
-    now.saturating_sub(last) >= CHECK_INTERVAL_SECS
+    return false;
 }
 
 pub fn record_check_done() {
