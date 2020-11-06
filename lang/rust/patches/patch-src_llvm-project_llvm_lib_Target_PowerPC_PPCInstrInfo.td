$NetBSD: patch-src_llvm-project_llvm_lib_Target_PowerPC_PPCInstrInfo.td,v 1.1 2020/11/06 20:13:49 he Exp $

Apply fix from
https://github.com/llvm/llvm-project/commit/a5d161c119d5a03c1ce834c6f4ce2576d6a064e4
so we avoid emitting a 64-bit-only instruction in 32-bit ppc code.

--- src/llvm-project/llvm/lib/Target/PowerPC/PPCInstrInfo.td.orig	2020-07-07 06:39:17.000000000 +0000
+++ src/llvm-project/llvm/lib/Target/PowerPC/PPCInstrInfo.td
@@ -5025,8 +5025,11 @@ def RotateInsertByte1 {
   dag Left = (RLWIMI RotateInsertByte3.Left, Swap4.Bits, 8, 24, 31);
 }
 
-def : Pat<(i32 (bitreverse i32:$A)),
-  (RLDICL_32 RotateInsertByte1.Left, 0, 32)>;
+// Clear the upper half of the register when in 64-bit mode
+let Predicates = [In64BitMode] in
+def : Pat<(i32 (bitreverse i32:$A)), (RLDICL_32 RotateInsertByte1.Left, 0, 32)>;
+let Predicates = [In32BitMode] in
+def : Pat<(i32 (bitreverse i32:$A)), RotateInsertByte1.Left>;
 
 // Fast 64-bit reverse bits algorithm:
 // Step 1: 1-bit swap (swap odd 1-bit and even 1-bit):
