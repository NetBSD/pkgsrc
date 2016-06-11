$NetBSD: patch-src_cdb.c,v 1.1 2016/06/11 18:41:56 kamil Exp $

Fix name clash with builtin 'round'.

--- src/cdb.c.orig	2000-12-25 00:49:07.000000000 +0000
+++ src/cdb.c
@@ -1564,7 +1564,7 @@ subst_eval(inpStr, result)
             (warriorsLeft ? warriorsLeft : 1));
     substitute(buf[bi1], "CYCLE", outs, buf[bi2]);
     SWITCHBI;
-    sprintf(outs, "%d", round);
+    sprintf(outs, "%d", sim_round);
     substitute(buf[bi1], "ROUND", outs, buf[bi2]);
 
     SWITCHBI;
@@ -1875,7 +1875,7 @@ print_registers()
 #endif
   int     nFuture, nPast, count, taskHalf = (coreSize <= 10000 ? 7 : 5);
 
-  sprintf(outs, roundOfCycle, round, rounds,
+  sprintf(outs, roundOfCycle, sim_round, rounds,
           (cycle + (warriorsLeft ? warriorsLeft : 1) - 1) /
           (warriorsLeft ? warriorsLeft : 1));
   cdb_fputs(outs, COND);
