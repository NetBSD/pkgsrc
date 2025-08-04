$NetBSD: patch-src_hotspot_cpu_aarch64_frame__aarch64.hpp,v 1.1 2025/08/04 13:22:06 pho Exp $

Backport a bugfix appeared in Java 22:
https://github.com/openjdk/jdk21u-dev/commit/9e582fcbb8ab34b44ff01ac13de5cc4d6487396d

--- src/hotspot/cpu/aarch64/frame_aarch64.hpp.orig	2025-08-01 18:15:42.300499547 +0000
+++ src/hotspot/cpu/aarch64/frame_aarch64.hpp
@@ -95,7 +95,7 @@
     // Entry frames
     // n.b. these values are determined by the layout defined in
     // stubGenerator for the Java call stub
-    entry_frame_after_call_words                     = 27,
+    entry_frame_after_call_words                     = 29,
     entry_frame_call_wrapper_offset                  = -8,
 
     // we don't need a save area
