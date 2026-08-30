$NetBSD: patch-src_stats.rs,v 1.2 2026/08/30 08:57:44 he Exp $

Improve portability to 32-bit CPUs.
Reported upstream at https://github.com/mihaigalos/dusage/pull/67

--- src/stats.rs.orig	2026-08-30 08:17:54.285693493 +0000
+++ src/stats.rs
@@ -50,7 +50,7 @@ impl Stats {
             }
         };
 
-        let fragment_size: u64 = statvfs.fragment_size();
+        let fragment_size: u64 = statvfs.fragment_size().into();
 
         // Calculate disk usage stats
         let size_disk = blocks * fragment_size;
