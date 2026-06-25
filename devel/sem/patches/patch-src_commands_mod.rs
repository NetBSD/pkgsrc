$NetBSD: patch-src_commands_mod.rs,v 1.1 2026/06/25 12:50:40 pin Exp $

Disable self-update.
https://github.com/Ataraxy-Labs/sem/pull/391

--- src/commands/mod.rs.orig	2026-06-25 10:44:59.593989124 +0000
+++ src/commands/mod.rs
@@ -10,7 +10,21 @@ pub mod stats;
 pub mod orient;
 pub mod setup;
 pub mod stats;
+#[cfg(feature = "self-update")]
 pub mod update;
+
+#[cfg(not(feature = "self-update"))]
+pub mod update {
+    pub fn maybe_notify(_command: &str) {}
+    pub fn background_check() {}
+    pub fn run() -> Result<(), Box<dyn std::error::Error>> {
+        println!(
+            "This build of sem has self-update disabled. Update it through the \
+             package manager it was installed with (e.g. pkgsrc, Homebrew, apt)."
+        );
+        Ok(())
+    }
+}
 
 use sem_core::parser::plugins::create_default_registry;
 use sem_core::parser::registry::ParserRegistry;
