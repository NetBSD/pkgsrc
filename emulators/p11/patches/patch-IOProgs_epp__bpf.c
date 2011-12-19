$NetBSD: patch-IOProgs_epp__bpf.c,v 1.1 2011/12/19 16:20:56 wiz Exp $

Avoid using compiler-defined names.

--- IOProgs/epp_bpf.c.orig	2000-12-04 17:03:43.000000000 +0000
+++ IOProgs/epp_bpf.c
@@ -193,7 +193,7 @@ void
 gen_filter()
 {
 	Bpf_insn *p = insns;
-	Bpf_insn *true, *false;
+	Bpf_insn *btrue, *bfalse;
 	u_long hw, hl;
 	u_int i;
 
@@ -207,16 +207,16 @@ gen_filter()
 		/*
 		 * all, but ours
 	 	 */
-		false = &insns[4];
-		true = false + 1;
+		bfalse = &insns[4];
+		btrue = bfalse + 1;
 		hw = SPLIT_W2(hwaddr);
 		hl = SPLIT_H0(hwaddr);
 		GEN_STMT(p, BPF_LD+BPF_W+BPF_ABS,	8);
-		GEN_JUMP(p, BPF_JMP+BPF_JEQ+BPF_K,	hw, 0, true-(p+1));
+		GEN_JUMP(p, BPF_JMP+BPF_JEQ+BPF_K,	hw, 0, btrue-(p+1));
 		GEN_STMT(p, BPF_LD+BPF_H+BPF_ABS,	6);
-		GEN_JUMP(p, BPF_JMP+BPF_JEQ+BPF_K,	hl, 0, true-(p+1));
+		GEN_JUMP(p, BPF_JMP+BPF_JEQ+BPF_K,	hl, 0, btrue-(p+1));
 
-		assert(p == false);
+		assert(p == bfalse);
 		GEN_STMT(p, BPF_RET+BPF_K, 0);
 		GEN_STMT(p, BPF_RET+BPF_K, (u_int)-1);
 
@@ -224,10 +224,10 @@ gen_filter()
 		/*
 		 * normal and, perhaps, allmulti
 		 */
-		false = &insns[f.naddr * 4 	/* 4 instructions per address */
+		bfalse = &insns[f.naddr * 4 	/* 4 instructions per address */
 			    + 4 		/* filter for own address */
 			    + 2 * (f.allmulti != 0)];
-		true = false + 1;
+		btrue = bfalse + 1;
 
 		/*
 		 * filter own packets
@@ -237,11 +237,11 @@ gen_filter()
 		GEN_STMT(p, BPF_LD+BPF_W+BPF_ABS,	8);
 		GEN_JUMP(p, BPF_JMP+BPF_JEQ+BPF_K,	hw, 0, 2);
 		GEN_STMT(p, BPF_LD+BPF_H+BPF_ABS,	6);
-		GEN_JUMP(p, BPF_JMP+BPF_JEQ+BPF_K,	hl, false-(p+1), 0);
+		GEN_JUMP(p, BPF_JMP+BPF_JEQ+BPF_K,	hl, bfalse-(p+1), 0);
 
 		if(f.allmulti) {
 			GEN_STMT(p, BPF_LD+BPF_B+BPF_ABS,	0);
-			GEN_JUMP(p, BPF_JMP+BPF_JSET+BPF_K,	1, true-(p+1), 0);
+			GEN_JUMP(p, BPF_JMP+BPF_JSET+BPF_K,	1, btrue-(p+1), 0);
 		}
 
 		for(i = 0; i < f.naddr; i++) {
@@ -250,9 +250,9 @@ gen_filter()
 			GEN_STMT(p, BPF_LD+BPF_W+BPF_ABS,	2);
 			GEN_JUMP(p, BPF_JMP+BPF_JEQ+BPF_K,	hw, 0, 2);
 			GEN_STMT(p, BPF_LD+BPF_H+BPF_ABS,	0);
-			GEN_JUMP(p, BPF_JMP+BPF_JEQ+BPF_K,	hl, true-(p+1), 0);
+			GEN_JUMP(p, BPF_JMP+BPF_JEQ+BPF_K,	hl, btrue-(p+1), 0);
 		}
-		assert(p == false);
+		assert(p == bfalse);
 		GEN_STMT(p, BPF_RET+BPF_K, 0);
 		GEN_STMT(p, BPF_RET+BPF_K, (u_int)-1);
 	}
