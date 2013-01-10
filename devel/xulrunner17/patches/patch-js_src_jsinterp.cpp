$NetBSD: patch-js_src_jsinterp.cpp,v 1.1 2013/01/10 16:17:10 ryoon Exp $

--- js/src/jsinterp.cpp.orig	2012-11-04 13:25:04.000000000 +0000
+++ js/src/jsinterp.cpp
@@ -3684,6 +3684,7 @@ BEGIN_CASE(JSOP_LEAVEBLOCK)
 BEGIN_CASE(JSOP_LEAVEFORLETIN)
 BEGIN_CASE(JSOP_LEAVEBLOCKEXPR)
 {
+  {
     DebugOnly<uint32_t> blockDepth = regs.fp()->blockChain().stackDepth();
 
     regs.fp()->popBlock(cx);
@@ -3698,7 +3699,9 @@ BEGIN_CASE(JSOP_LEAVEBLOCKEXPR)
         regs.sp -= GET_UINT16(regs.pc);
         JS_ASSERT(regs.stackDepth() == blockDepth + 1);
         regs.sp[-1] = *vp;
-    } else {
+    }
+  }
+    if (op != JSOP_LEAVEBLOCK && op != JSOP_LEAVEBLOCKEXPR)  {
         /* Another op will pop; nothing to do here. */
         len = JSOP_LEAVEFORLETIN_LENGTH;
         DO_NEXT_OP(len);
