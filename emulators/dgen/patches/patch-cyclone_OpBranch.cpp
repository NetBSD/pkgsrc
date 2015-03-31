$NetBSD: patch-cyclone_OpBranch.cpp,v 1.1 2015/03/31 15:20:53 joerg Exp $

--- cyclone/OpBranch.cpp.orig	2013-02-09 20:26:18.000000000 +0000
+++ cyclone/OpBranch.cpp
@@ -336,7 +336,7 @@ int OpDbra(int op)
       break;
     default:
       ot(";@ Is the condition true?\n");
-      ot("  msr cpsr_flg,r10 ;@ ARM flags = 68000 flags\n");
+      ot("  msr CPSR_f,r10 ;@ ARM flags = 68000 flags\n");
       ot(";@ If so, don't dbra\n");
       ot("  b%s DbraTrue\n\n",Cond[cc]);
       break;
@@ -449,7 +449,7 @@ int OpBranch(int op)
       break;
     default:
       ot(";@ Is the condition true?\n");
-      ot("  msr cpsr_flg,r10 ;@ ARM flags = 68000 flags\n");
+      ot("  msr CPSR_f,r10 ;@ ARM flags = 68000 flags\n");
       ot("  b%s BccDontBranch%i\n\n",Cond[cc^1],8<<size);
       break;
   }
