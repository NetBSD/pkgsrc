$NetBSD: patch-spunk_unixsrc_delay.cc,v 1.1 2012/11/16 00:37:47 joerg Exp $

--- spunk/unixsrc/delay.cc.orig	1996-11-07 18:06:58.000000000 +0000
+++ spunk/unixsrc/delay.cc
@@ -73,7 +73,7 @@ u32 Delay (u32 ms)
 //
 // The function returns the real time passed or just ms.
 {
-    const ChunkSize = 256;
+    const u32 ChunkSize = 256;
 
     // Check the argument...
     if (ms <= ChunkSize) {
