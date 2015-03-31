$NetBSD: patch-cyclone_OpLogic.cpp,v 1.1 2015/03/31 15:20:53 joerg Exp $

--- cyclone/OpLogic.cpp.orig	2013-02-09 20:26:18.000000000 +0000
+++ cyclone/OpLogic.cpp
@@ -362,7 +362,7 @@ int OpSet(int op)
       break;
     default:
       ot(";@ Is the condition true?\n");
-      ot("  msr cpsr_flg,r10 ;@ ARM flags = 68000 flags\n");
+      ot("  msr CPSR_f,r10 ;@ ARM flags = 68000 flags\n");
       ot("  mvn%s r1,r1\n",cond[cc]);
       if (ea<8) ot("  sub%s r5,r5,#2 ;@ Extra cycles\n",cond[cc]);
       break;
@@ -487,7 +487,7 @@ static int EmitAsr(int op,int type,int d
       if (size==2)
       {
         ot("  subs r2,r2,#33\n");
-        ot("  addmis r2,r2,#33 ;@ Now r2=0-%d\n",wide);
+        ot("  addsmi r2,r2,#33 ;@ Now r2=0-%d\n",wide);
       }
       else
       {
