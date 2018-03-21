$NetBSD: patch-src_cpus_memory__ppc.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/cpus/memory_ppc.cc.orig	2014-08-17 08:45:15.000000000 +0000
+++ src/cpus/memory_ppc.cc
@@ -270,7 +270,7 @@ int ppc_translate_v2p(struct cpu *cpu, u
 		return 0;
 
 	if (!quiet_mode)
-		fatal("[ memory_ppc: exception! vaddr=0x%"PRIx64" pc=0x%"PRIx64
+		fatal("[ memory_ppc: exception! vaddr=0x%" PRIx64 " pc=0x%" PRIx64
 		    " instr=%i user=%i wf=%i ]\n", (uint64_t) vaddr,
 		    (uint64_t) cpu->pc, instr, user, writeflag);
 
@@ -295,4 +295,3 @@ int ppc_translate_v2p(struct cpu *cpu, u
 
 	return 0;
 }
-
