$NetBSD: patch-cyclone_Main.cpp,v 1.1 2015/03/31 15:20:53 joerg Exp $

--- cyclone/Main.cpp.orig	2013-02-09 20:26:18.000000000 +0000
+++ cyclone/Main.cpp
@@ -275,7 +275,7 @@ static void PrintFramework()
   ot("  cmp r2,#0xf\n");
   ot("  addeq r2,r2,#1 ;@ 0xf is really 0x10\n");
   ot("  tst r2,r2\n");
-  ot("  ldreqh r2,[r0],#2 ;@ counter is in next word\n");
+  ot("  ldrheq r2,[r0],#2 ;@ counter is in next word\n");
   ot("  tst r2,r2\n");
   ot("  beq unc_finish ;@ done decompressing\n");
   ot("  tst r1,r1\n");
@@ -570,7 +570,7 @@ static void PrintFramework()
   ot("  ldr r3,[r7,#0x8c] ;@ IrqCallback\n");
   ot("  add lr,pc,#4*3\n");
   ot("  tst r3,r3\n");
-  ot("  streqb r3,[r7,#0x47] ;@ just clear IRQ if there is no callback\n");
+  ot("  strbeq r3,[r7,#0x47] ;@ just clear IRQ if there is no callback\n");
   ot("  mvneq r0,#0 ;@ and simulate -1 return\n");
   ot("  bxne r3\n");
 #if INT_ACK_CHANGES_CYCLES
