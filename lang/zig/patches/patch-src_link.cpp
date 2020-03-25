$NetBSD: patch-src_link.cpp,v 1.3 2020/03/25 22:27:20 nia Exp $

NetBSD fixes. Based on:
https://github.com/ziglang/zig/pull/4793

--- src/link.cpp.orig	2019-09-30 15:40:00.000000000 +0000
+++ src/link.cpp
@@ -1805,7 +1805,9 @@ static void construct_linker_job_elf(Lin
                 }
             }
 
-            if (g->zig_target->os == OsFreeBSD) {
+            if (g->zig_target->os == OsFreeBSD ||
+                g->zig_target->os == OsNetBSD)
+            {
                 lj->args.append("-lpthread");
             }
         } else if (target_is_glibc(g->zig_target)) {
