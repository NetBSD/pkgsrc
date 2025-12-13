$NetBSD: patch-src_fork__exec_spawn.rs,v 1.1 2025/12/13 17:47:21 vins Exp $

Prevent mismatched types for POSIX_SPAWN_SETSIGDEF on SunOS.

--- src/fork_exec/spawn.rs.orig	2025-10-07 20:56:06.000000000 +0000
+++ src/fork_exec/spawn.rs
@@ -117,7 +117,12 @@ impl PosixSpawner {
         };
 
         // Set our flags.
-        let mut flags: i32 = 0;
+        cfg_if::cfg_if! {
+            if #[cfg(target_os = "illumos")] {
+                let mut flags: i16 = 0; } 
+            else  {
+                let mut flags: i32 = 0; }
+        }
         flags |= libc::POSIX_SPAWN_SETSIGDEF;
         flags |= libc::POSIX_SPAWN_SETSIGMASK;
         if desired_pgid.is_some() {
