$NetBSD: patch-src_algo_blast_core_blast__kappa.c,v 1.2 2019/01/07 15:00:10 bacon Exp $

# Work around NetBSD stderr def choking macro

--- src/algo/blast/core/blast_kappa.c.orig	2019-01-02 04:00:17.000000000 +0000
+++ src/algo/blast/core/blast_kappa.c
@@ -32,6 +32,7 @@
  * system for each match in blastpgp
  */
 
+#include <stdio.h>
 #include <float.h>
 #include <algo/blast/core/ncbi_math.h>
 #include <algo/blast/core/blast_hits.h>
@@ -57,7 +58,7 @@
  * shared(...) list. */
 #    define STDERR_COMMA
 #  else
-#    define STDERR_COMMA stderr,
+#    define STDERR_COMMA my_stderr,
 #  endif
 #endif
 
@@ -3412,6 +3413,8 @@ Blast_RedoAlignmentCore_MT(EBlastProgram
     }
 
     Boolean interrupt = FALSE;
+    /* NetBSD defines stderr as (&__sF[2]), which the macro below chokes on */
+    FILE *my_stderr = stderr;
 #pragma omp parallel \
     default(none) num_threads(actual_num_threads) \
     if(actual_num_threads>1) \
