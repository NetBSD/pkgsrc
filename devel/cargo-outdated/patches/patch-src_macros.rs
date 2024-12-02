$NetBSD: patch-src_macros.rs,v 1.1 2024/12/02 20:26:21 adam Exp $

Fix build for Rust 1.80.0 and newer.
https://github.com/kbknapp/cargo-outdated/pull/403

--- src/macros.rs.orig	2024-02-26 16:23:06.000000000 +0000
+++ src/macros.rs
@@ -1,6 +1,6 @@
 macro_rules! verbose {
-    ($config:expr, $status:expr, $message:expr) => {
-        $config
+    ($context:expr, $status:expr, $message:expr) => {
+        $context
             .shell()
             .verbose(|sh| -> CargoResult<()> { sh.status($status, $message) })?
     };
@@ -8,16 +8,16 @@ macro_rules! verbose {
 
 #[cfg(feature = "debug")]
 macro_rules! debug {
-    ($config: expr, $message: expr) => (
-        $config.shell().status_with_color("DEBUG", $message, &Default::default())?
+    ($context: expr, $message: expr) => (
+        $context.shell().status_with_color("DEBUG", $message, &Default::default())?
     );
-    ($config: expr, $($arg: tt)*) => (
-        $config.shell().status_with_color("DEBUG", format!($($arg)*), &Default::default())?
+    ($context: expr, $($arg: tt)*) => (
+        $context.shell().status_with_color("DEBUG", format!($($arg)*), &Default::default())?
     );
 }
 
 #[cfg(not(feature = "debug"))]
 macro_rules! debug {
-    ($config:expr, $message:expr) => {};
-    ($config:expr, $($arg:tt)*) => {};
+    ($context:expr, $message:expr) => {};
+    ($context:expr, $($arg:tt)*) => {};
 }
