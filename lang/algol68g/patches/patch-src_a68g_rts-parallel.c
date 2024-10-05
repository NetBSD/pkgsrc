$NetBSD: patch-src_a68g_rts-parallel.c,v 1.1 2024/10/05 15:51:02 rhialto Exp $

Don't examine errno if the operation didn't fail.
This resulted in a false positive.

--- src/a68g/rts-parallel.c.orig	2024-08-30 22:34:06.000000000 +0000
+++ src/a68g/rts-parallel.c
@@ -382,10 +382,12 @@ PROP_T genie_parallel (NODE_T * p)
       diagnostic (A68_RUNTIME_ERROR, p, ERROR_PARALLEL_CANNOT_CREATE);
       exit_genie (p, A68_RUNTIME_ERROR);
     }
+#if 0 /* Don't examine errno if the operation didn't fail */
     if (errno != 0) {
       diagnostic (A68_RUNTIME_ERROR, p, ERROR_THREAD_FAULT);
       exit_genie (p, A68_RUNTIME_ERROR);
     }
+#endif
     PARENT (u) = A68_PAR (main_thread_id);
     ID (u) = A68_PAR (parent_thread_id);
     A68_PAR (context_index)++;
