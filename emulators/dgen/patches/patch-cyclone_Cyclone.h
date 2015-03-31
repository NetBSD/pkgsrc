$NetBSD: patch-cyclone_Cyclone.h,v 1.1 2015/03/31 15:20:53 joerg Exp $

--- cyclone/Cyclone.h.orig	2013-02-09 20:26:18.000000000 +0000
+++ cyclone/Cyclone.h
@@ -35,7 +35,7 @@ struct Cyclone
   int state_flags;      // [r7,#0x58] bit: 0: stopped state, 1: trace state, 2: activity bit, 3: addr error, 4: fatal halt
   int cycles;           // [r7,#0x5c] Number of cycles to execute - 1. Updates to cycles left after CycloneRun()
   int membase;          // [r7,#0x60] Memory Base (ARM address minus 68000 address)
-  unsigned int (*checkpc)(unsigned int pc); // [r7,#0x64] called to recalc Memory Base+pc
+  uintptr_t (*checkpc)(uintptr_t pc); // [r7,#0x64] called to recalc Memory Base+pc
   unsigned int (*read8  )(unsigned int a);  // [r7,#0x68]
   unsigned int (*read16 )(unsigned int a);  // [r7,#0x6c]
   unsigned int (*read32 )(unsigned int a);  // [r7,#0x70]
