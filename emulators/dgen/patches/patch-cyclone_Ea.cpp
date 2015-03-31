$NetBSD: patch-cyclone_Ea.cpp,v 1.1 2015/03/31 15:20:53 joerg Exp $

--- cyclone/Ea.cpp.orig	2013-02-09 20:26:18.000000000 +0000
+++ cyclone/Ea.cpp
@@ -225,7 +225,7 @@ int EaCalc(int a,int mask,int ea,int siz
     ot("  mov r2,r3,lsr #10\n");
     ot("  tst r3,#0x0800 ;@ Is Rn Word or Long\n");
     ot("  and r2,r2,#0x3c ;@ r2=Index of Rn\n");
-    ot("  ldreqsh r2,[r7,r2] ;@ r2=Rn.w\n");
+    ot("  ldrsheq r2,[r7,r2] ;@ r2=Rn.w\n");
     ot("  ldrne   r2,[r7,r2] ;@ r2=Rn.l\n");
     ot("  mov r0,r3,asl #24 ;@ r0=Get 8-bit signed Disp\n");
     ot("  add r3,r2,r0,asr #24 ;@ r3=Disp+Rn\n");
@@ -274,7 +274,7 @@ int EaCalc(int a,int mask,int ea,int siz
     ot("  mov r2,r3,lsr #10\n");
     ot("  tst r3,#0x0800 ;@ Is Rn Word or Long\n");
     ot("  and r2,r2,#0x3c ;@ r2=Index of Rn\n");
-    ot("  ldreqsh r2,[r7,r2] ;@ r2=Rn.w\n");
+    ot("  ldrsheq r2,[r7,r2] ;@ r2=Rn.w\n");
     ot("  ldrne   r2,[r7,r2] ;@ r2=Rn.l\n");
     ot("  mov r3,r3,asl #24 ;@ r3=Get 8-bit signed Disp\n");
     ot("  add r2,r2,r3,asr #24 ;@ r2=Disp+Rn\n");
