$NetBSD: patch-src_fork__exec_spawn.rs,v 1.1 2025/11/02 18:44:07 vins Exp $

Prevent mismatched types for POSIX_SPAWN_SETSIGDEF on SunOS.

--- src/fork_exec/spawn.rs.orig	2025-10-07 20:56:06.000000000 +0000
+++ src/fork_exec/spawn.rs
@@ -117,6 +117,9 @@ impl PosixSpawner {
         };
 
         // Set our flags.
+        #[cfg(target_os = "illumos")]
+        let mut flags: i16 = 0;
+        #[cfg(not(target_os = "illumos"))]
         let mut flags: i32 = 0;
         flags |= libc::POSIX_SPAWN_SETSIGDEF;
         flags |= libc::POSIX_SPAWN_SETSIGMASK;
