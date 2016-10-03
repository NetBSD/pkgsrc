$NetBSD: patch-js_src_assembler_assembler_MIPSAssembler.h,v 1.1 2016/10/03 02:46:47 maya Exp $

blindly convert all nops to EHB / SSNOP
nop doesn't eliminate hazards in a superscalar CPU

--- js/src/assembler/assembler/MIPSAssembler.h.orig	2013-02-11 22:33:22.000000000 +0000
+++ js/src/assembler/assembler/MIPSAssembler.h
@@ -243,7 +243,10 @@ public:
 
     void nop()
     {
-        emitInst(0x00000000);
+	/* nop is insufficient for eliminating hazards
+	 * in a superscalar CPU. blindly convert all to
+	 * MIPSNNR6 ehb / ssnop, at a performance cost. */
+        emitInst(0x000000c0);
     }
 
     /* Need to insert one load data delay nop for mips1.  */
