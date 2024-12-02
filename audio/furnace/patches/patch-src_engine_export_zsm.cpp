$NetBSD: patch-src_engine_export_zsm.cpp,v 1.1 2024/12/02 07:47:47 nia Exp $

Fix "error: call of overloaded 'log(int)' is ambiguous" on SunOS.

--- src/engine/export/zsm.cpp.orig	2024-12-02 07:46:38.294426934 +0000
+++ src/engine/export/zsm.cpp
@@ -618,7 +618,7 @@ void DivExportZSM::run() {
     // Tunings offsets that exceed a half semitone
     // will simply be represented in a different key
     // by nature of overflowing the signed char value
-    signed char tuningoffset=(signed char)(round(3072*(log(e->song.tuning/440.0)/log(2))))&0xff;
+    signed char tuningoffset=(signed char)(round(3072*(log(e->song.tuning/440.0)/log(2.0))))&0xff;
     zsm.writeSync(0x01,tuningoffset);
     // Set optimize flag, which mainly buffers PSG writes
     // whenever the channel is silent
