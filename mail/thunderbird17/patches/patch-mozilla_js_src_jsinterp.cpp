$NetBSD: patch-mozilla_js_src_jsinterp.cpp,v 1.1 2013/11/13 13:27:45 ryoon Exp $

--- mozilla/js/src/jsinterp.cpp.orig	2012-11-19 22:42:24.000000000 +0000
+++ mozilla/js/src/jsinterp.cpp
@@ -3664,6 +3664,7 @@ BEGIN_CASE(JSOP_LEAVEBLOCK)
 BEGIN_CASE(JSOP_LEAVEFORLETIN)
 BEGIN_CASE(JSOP_LEAVEBLOCKEXPR)
 {
+  {
     DebugOnly<uint32_t> blockDepth = regs.fp()->blockChain().stackDepth();
 
     regs.fp()->popBlock(cx);
@@ -3678,7 +3679,9 @@ BEGIN_CASE(JSOP_LEAVEBLOCKEXPR)
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
