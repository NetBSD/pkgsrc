$NetBSD: patch-src_sim.c,v 1.1 2016/06/11 18:41:56 kamil Exp $

Fix name clash with builtin 'round'.

--- src/sim.c.orig	2000-12-25 00:49:08.000000000 +0000
+++ src/sim.c
@@ -177,7 +177,7 @@ ADDR_T AA_Value, AB_Value;
 mem_struct FAR *memory;
 
 long    cycle;
-int     round;
+int     sim_round;
 
 char    alloc_p = 0;                /* indicate whether memory has been allocated */
 int     warriorsLeft;                /* number of warriors still left in core */
@@ -311,7 +311,7 @@ register  int     temp;                 
 #endif
 
   display_init();
-  round = 1;
+  sim_round = 1;
   do {                                /* each round */
 #if defined(DOS16) && !defined(SERVER) && !defined(DOSTXTGRAPHX) && !defined(DOSGRXGRAPHX) && !defined(DJGPP)
     fputc('\r', stdout);        /* enable interruption by Ctrl-C */
@@ -1325,13 +1325,13 @@ nextround:
 #ifndef SERVER
     if (debugState == BREAK) {
       if (warriorsLeft == 1 && warriors != 1)
-	sprintf(outs, warriorTerminatedEndOfRound, W - warrior, W->name, round);
+	sprintf(outs, warriorTerminatedEndOfRound, W - warrior, W->name, sim_round);
       else
-	sprintf(outs, endOfRound, round);
+	sprintf(outs, endOfRound, sim_round);
       debugState = cdb(outs);
     }
 #endif
-  } while (++round <= rounds);
+  } while (++sim_round <= rounds);
 
   display_close();
 #ifdef PERMUTATE
