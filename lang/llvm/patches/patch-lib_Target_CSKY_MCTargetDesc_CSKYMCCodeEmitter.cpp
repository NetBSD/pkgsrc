$NetBSD: patch-lib_Target_CSKY_MCTargetDesc_CSKYMCCodeEmitter.cpp,v 1.1 2024/07/02 18:14:26 cheusov Exp $

Fix build failure on Linux caused by -Werror=return-type

https://github.com/llvm/llvm-project/issues/97456

--- lib/Target/CSKY/MCTargetDesc/CSKYMCCodeEmitter.cpp~	2023-11-28 08:52:28.000000000 +0000
+++ lib/Target/CSKY/MCTargetDesc/CSKYMCCodeEmitter.cpp	2024-07-01 21:55:32.992601162 +0000
@@ -297,7 +297,7 @@
   else if (MI.getOperand(Idx).getImm() == 40)
     return 3;
   else
-    assert(0);
+    abort();
 }
 
 MCFixupKind CSKYMCCodeEmitter::getTargetFixup(const MCExpr *Expr) const {
