$NetBSD: patch-src_algo_blast_core_blast__kappa.c,v 1.1 2018/04/27 20:28:28 bacon Exp $

# Work around NetBSD stderr def choking macro

--- src/algo/blast/core/blast_kappa.c.orig	2018-03-26 21:55:44.000000000 +0000
+++ src/algo/blast/core/blast_kappa.c
@@ -32,6 +32,7 @@
  * system for each match in blastpgp
  */
 
+#include <stdio.h>
 #include <float.h>
 #include <algo/blast/core/ncbi_math.h>
 #include <algo/blast/core/blast_hits.h>
@@ -3404,13 +3405,15 @@ Blast_RedoAlignmentCore_MT(EBlastProgram
     }
 
     Boolean interrupt = FALSE;
+    /* NetBSD defines stderr as (&__sF[2]), which the macro below chokes on */
+    FILE *my_stderr = stderr;
 #pragma omp parallel \
     default(none) num_threads(actual_num_threads) \
     if(actual_num_threads>1) \
     shared(interrupt, seqsrc_tld, score_params_tld, hit_params_tld, \
     gap_align_tld, results_tld, \
     redoneMatches_tld, \
-    stderr, \
+    my_stderr, \
     numQueries, numMatches, theseMatches, \
     numFrames, program_number, subjectBlk_tld, positionBased, \
     default_db_genetic_code, localScalingFactor, queryInfo, \
