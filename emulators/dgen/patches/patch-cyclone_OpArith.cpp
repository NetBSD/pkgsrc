$NetBSD: patch-cyclone_OpArith.cpp,v 1.1 2015/03/31 15:20:53 joerg Exp $

--- cyclone/OpArith.cpp.orig	2013-02-09 20:26:18.000000000 +0000
+++ cyclone/OpArith.cpp
@@ -373,7 +373,7 @@ int GetXBit(int subtract)
   ot(";@ Get X bit:\n");
   ot("  ldr r2,[r7,#0x4c]\n");
   if (subtract) ot("  mvn r2,r2 ;@ Invert it\n");
-  ot("  msr cpsr_flg,r2 ;@ Get into Carry\n");
+  ot("  msr CPSR_f,r2 ;@ Get into Carry\n");
   ot("\n");
   return 0;
 }
