$NetBSD: patch-src_cpus_cpu__ppc__instr.cc,v 1.1 2018/03/21 17:39:42 kamil Exp $

Fix C++11 literals.

--- src/cpus/cpu_ppc_instr.cc.orig	2014-08-17 08:45:15.000000000 +0000
+++ src/cpus/cpu_ppc_instr.cc
@@ -2780,7 +2780,7 @@ X(to_be_translated)
 		} else {
 			if (!cpu->translation_readahead)
 				fatal("[ TODO: Unimplemented ALTIVEC, iword"
-				    " = 0x%08"PRIx32"x ]\n", iword);
+				    " = 0x%08" PRIx32 "x ]\n", iword);
 			goto bad;
 		}
 		break;
@@ -3918,4 +3918,3 @@ X(to_be_translated)
 #include "cpu_dyntrans.cc"
 #undef	DYNTRANS_TO_BE_TRANSLATED_TAIL
 }
-
