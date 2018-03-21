$NetBSD: patch-src_cpus_memory__sh.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/cpus/memory_sh.cc.orig	2014-08-17 08:45:15.000000000 +0000
+++ src/cpus/memory_sh.cc
@@ -293,7 +293,7 @@ int sh_translate_v2p(struct cpu *cpu, ui
 	}
 
 	if (flags & FLAG_INSTR) {
-		fatal("TODO: instr at 0x%08"PRIx32"\n", (uint32_t)vaddr);
+		fatal("TODO: instr at 0x%08" PRIx32 "\n", (uint32_t)vaddr);
 		exit(1);
 	}
 
@@ -312,10 +312,9 @@ int sh_translate_v2p(struct cpu *cpu, ui
 
 	/*  The ugly 'if' is just here to fool Compaq CC.  */
 	if (!(flags & FLAG_NOEXCEPTIONS)) {
-		fatal("Unimplemented SH vaddr 0x%08"PRIx32"\n", vaddr);
+		fatal("Unimplemented SH vaddr 0x%08" PRIx32 "\n", vaddr);
 		exit(1);
 	}
 
 	return 0;
 }
-
